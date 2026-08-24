<#
.SYNOPSIS
    Programming Study 볼트를 자동으로 커밋하고 푸시합니다.

.DESCRIPTION
    VS Code 에는 "창을 닫을 때" 실행되는 훅이 없습니다. 그래서 이 스크립트는
    폴더를 열 때 백그라운드로 뜬 뒤(.vscode/tasks.json 의 folderOpen 태스크),
    변경사항이 생기고 -IdleSeconds 만큼 조용해지면 커밋 + pull --rebase + push
    를 수행합니다. 즉 편집을 멈춘 지 20초쯤 지나면 이미 푸시가 끝나 있으므로,
    창을 언제 닫아도 내용이 남습니다.

    창을 닫는 "그 순간"까지 확실히 보장하고 싶으면 tools/study.ps1 로 VS Code 를
    여세요. code --wait 로 창이 닫히는 것을 기다렸다가 마지막 동기화를 합니다.

.PARAMETER VaultPath
    볼트(리포지터리) 경로. 생략하면 현재 디렉터리.

.PARAMETER IdleSeconds
    변경이 멈춘 뒤 몇 초 후에 커밋할지. 기본 20초.

.PARAMETER PollSeconds
    git status 를 몇 초 간격으로 확인할지. 기본 5초.

.PARAMETER Once
    감시하지 않고 지금 한 번만 커밋·푸시하고 종료.

.EXAMPLE
    powershell -ExecutionPolicy Bypass -File tools\auto-sync.ps1 -Once
#>

[CmdletBinding()]
param(
    [string]$VaultPath   = (Get-Location).Path,
    [int]   $IdleSeconds = 20,
    [int]   $PollSeconds = 5,
    [switch]$Once
)

$ErrorActionPreference = 'Continue'
$OutputEncoding = [System.Text.Encoding]::UTF8

# ─────────────────────────────────────────────────────────────
function Write-Log {
    param([string]$Message, [string]$Level = 'INFO')
    $line = "[{0}] {1,-5} {2}" -f (Get-Date -Format 'HH:mm:ss'), $Level, $Message
    switch ($Level) {
        'ERR'  { Write-Host $line -ForegroundColor Red }
        'WARN' { Write-Host $line -ForegroundColor Yellow }
        'OK'   { Write-Host $line -ForegroundColor Green }
        default{ Write-Host $line -ForegroundColor DarkGray }
    }
}

function Invoke-Git {
    # git 을 호출하고 종료코드와 출력을 함께 돌려줍니다.
    # 인자는 반드시 배열로 넘깁니다 — Invoke-Git @('add','-A') 처럼.
    # 그냥 늘어놓으면 '-A' 같은 토큰을 PowerShell 이 파라미터 이름으로
    # 해석해 버립니다.
    param([Parameter(Mandatory = $true)][string[]]$GitArgs)
    $out = & git @GitArgs 2>&1
    return [pscustomobject]@{
        Code   = $LASTEXITCODE
        Output = ($out | Out-String).Trim()
    }
}

# ─────────────────────────────────────────────────────────────
# 락 — Obsidian Git 플러그인이나 다른 VS Code 창과 동시에 돌아
# index.lock 충돌이 나는 것을 막습니다.
#
# 락 파일은 .git 폴더 안에 둡니다. git 이 절대 추적하지 않는 곳이라
# .gitignore 설정과 무관하게 커밋에 딸려 들어갈 일이 없습니다.
$LockMaxAge = [TimeSpan]::FromMinutes(5)

function Get-LockFilePath {
    param([string]$Root)
    $gitDir = (& git -C $Root rev-parse --absolute-git-dir 2>$null)
    if ($LASTEXITCODE -ne 0 -or [string]::IsNullOrWhiteSpace($gitDir)) {
        # git 을 못 부르는 상황 — 루트에 두되 .gitignore 가 막아 줍니다.
        return (Join-Path $Root '.git-autosync.lock')
    }
    return (Join-Path $gitDir.Trim() 'autosync.lock')
}

function Enter-SyncLock {
    if (Test-Path $LockFile) {
        $reason = $null

        # 락을 만든 프로세스가 아직 살아 있는지 봅니다. VS Code 는 창을 닫을 때
        # 태스크 프로세스를 강제 종료하므로 finally 가 못 돌고 락이 남는 일이
        # 흔합니다. 그 경우 주인이 이미 죽었으니 곧바로 가져옵니다.
        $ownerPid = 0
        $raw = (Get-Content $LockFile -TotalCount 1 -ErrorAction SilentlyContinue)
        if ([int]::TryParse([string]$raw, [ref]$ownerPid) -and $ownerPid -gt 0) {
            if ($ownerPid -eq $PID) {
                $reason = '내가 남긴 락'
            } elseif (-not (Get-Process -Id $ownerPid -ErrorAction SilentlyContinue)) {
                $reason = "주인 프로세스(PID $ownerPid)가 종료됨"
            }
        } else {
            $reason = '락 내용이 손상됨'
        }

        # PID 를 믿을 수 없는 경우(PID 재사용 등)를 대비한 안전망.
        if (-not $reason) {
            $age = (Get-Date) - (Get-Item $LockFile).LastWriteTime
            if ($age -ge $LockMaxAge) { $reason = "$([int]$age.TotalMinutes)분 경과" }
        }

        if (-not $reason) { return $false }
        Write-Log "묵은 락 제거 — $reason" 'WARN'
        Remove-Item $LockFile -Force -ErrorAction SilentlyContinue
    }
    try {
        Set-Content -Path $LockFile -Value $PID -Encoding ASCII -ErrorAction Stop
        return $true
    } catch { return $false }
}

function Exit-SyncLock {
    Remove-Item $LockFile -Force -ErrorAction SilentlyContinue
}

# ─────────────────────────────────────────────────────────────
function Sync-Vault {
    if (-not (Enter-SyncLock)) {
        Write-Log '다른 동기화가 진행 중 — 이번 차례는 건너뜁니다' 'WARN'
        return
    }
    try {
        $add = Invoke-Git @('add','-A')
        if ($add.Code -ne 0) { Write-Log "git add 실패: $($add.Output)" 'ERR'; return }

        # 스테이징된 변경이 없으면 커밋하지 않습니다 (빈 커밋 방지).
        $staged = Invoke-Git @('diff','--cached','--quiet')
        if ($staged.Code -eq 0) { Write-Log '변경사항 없음'; return }

        $summary = (Invoke-Git @('diff','--cached','--shortstat')).Output
        $msg     = "vault sync {0}" -f (Get-Date -Format 'yyyy-MM-dd HH:mm')
        $commit  = Invoke-Git @('commit','-m',$msg)
        if ($commit.Code -ne 0) { Write-Log "커밋 실패: $($commit.Output)" 'ERR'; return }
        Write-Log "커밋: $summary" 'OK'

        # 원격에 다른 기기(Obsidian Git 등)가 올린 커밋이 있을 수 있으므로
        # 항상 rebase pull 을 먼저 합니다.
        $pull = Invoke-Git @('pull','--rebase','--autostash')
        if ($pull.Code -ne 0) {
            Write-Log "pull --rebase 실패 — 충돌일 수 있습니다. 수동 확인 필요:" 'ERR'
            Write-Log $pull.Output 'ERR'
            Invoke-Git @('rebase','--abort') | Out-Null
            return
        }

        # 네트워크 오류에 대비해 지수 백오프로 재시도합니다.
        $delays = @(2, 4, 8, 16)
        for ($i = 0; $i -le $delays.Count; $i++) {
            $push = Invoke-Git @('push')
            if ($push.Code -eq 0) { Write-Log "푸시 완료" 'OK'; return }
            if ($i -lt $delays.Count) {
                Write-Log "푸시 실패 — $($delays[$i])초 후 재시도 ($($i + 1)/$($delays.Count))" 'WARN'
                Start-Sleep -Seconds $delays[$i]
            } else {
                Write-Log "푸시 최종 실패: $($push.Output)" 'ERR'
                Write-Log '커밋은 로컬에 남아 있습니다. 나중에 git push 로 올리세요.' 'WARN'
            }
        }
    }
    finally { Exit-SyncLock }
}

# ─────────────────────────────────────────────────────────────
if (-not (Test-Path (Join-Path $VaultPath '.git'))) {
    Write-Log "git 리포지터리가 아닙니다: $VaultPath" 'ERR'
    exit 1
}
Set-Location $VaultPath
$LockFile = Get-LockFilePath -Root $VaultPath

if ($Once) {
    Write-Log "한 번만 동기화합니다 — $VaultPath"
    Sync-Vault
    exit 0
}

Write-Log "자동 동기화 시작 — $VaultPath"
Write-Log "변경 후 ${IdleSeconds}초간 조용하면 커밋·푸시합니다. (중지: 이 터미널 종료)"

$lastState = ''
$quietFrom = $null

try {
    while ($true) {
        $state = (Invoke-Git @('status','--porcelain')).Output

        if ([string]::IsNullOrWhiteSpace($state)) {
            $lastState = ''
            $quietFrom = $null
        }
        elseif ($state -ne $lastState) {
            # 아직 편집 중 — 유휴 타이머를 다시 시작합니다.
            $lastState = $state
            $quietFrom = Get-Date
        }
        elseif ($quietFrom -and ((Get-Date) - $quietFrom).TotalSeconds -ge $IdleSeconds) {
            Sync-Vault
            $lastState = ''
            $quietFrom = $null
        }

        Start-Sleep -Seconds $PollSeconds
    }
}
finally {
    # 창이 정상적으로 닫히면 여기서 마지막 한 번을 더 시도합니다.
    # (강제 종료 시에는 실행되지 않을 수 있으므로 study.ps1 을 함께 쓰세요.)
    Write-Log '종료 중 — 마지막 동기화 시도'
    Sync-Vault
}
