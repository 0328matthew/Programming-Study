<#
.SYNOPSIS
    데스크톱의 기존 폴더들을 새 Programming Study 볼트 구조로 옮깁니다.

.DESCRIPTION
    GitHub 쪽 통합은 이미 끝났습니다. 이 스크립트는 로컬 PC 에서
    흩어져 있던 폴더들을 새 볼트 안의 제자리로 복사합니다.

      <CppNotes>       →  <Vault>\C++\개념
      <CppProjects>    →  <Vault>\C++\예제
      <PythonNotes>    →  <Vault>\Python\개념
      <PythonProjects> →  <Vault>\Python\예제

    기본값은 복사(copy)입니다. 원본은 그대로 두므로 안전합니다.
    실제로 실행하기 전에 -WhatIf 로 무엇이 옮겨지는지 먼저 확인하세요.

.EXAMPLE
    # 1) 미리보기 — 아무것도 바꾸지 않습니다
    .\migrate-local-vault.ps1 -Vault "C:\Users\0328m\Programming Study" `
        -CppProjects "C:\Users\0328m\cpp_project" `
        -PythonProjects "C:\Users\0328m\python_projects" -WhatIf

.EXAMPLE
    # 2) 실제 실행
    .\migrate-local-vault.ps1 -Vault "C:\Users\0328m\Programming Study" `
        -CppProjects "C:\Users\0328m\cpp_project" `
        -PythonProjects "C:\Users\0328m\python_projects"
#>

[CmdletBinding(SupportsShouldProcess = $true)]
param(
    [Parameter(Mandatory = $true)][string]$Vault,
    [string]$CppNotes,
    [string]$CppProjects,
    [string]$PythonNotes,
    [string]$PythonProjects
)

$ErrorActionPreference = 'Stop'

# ── 인코딩 자체 점검 ──────────────────────────────────────
# Windows PowerShell 5.1 은 BOM 없는 .ps1 을 UTF-8 이 아니라 시스템
# 코드페이지(한국어 Windows 는 cp949)로 읽습니다. 그러면 아래의
# '개념'·'예제' 리터럴이 깨져서 엉뚱한 폴더명이 만들어집니다.
# 이 파일은 UTF-8 BOM 으로 저장돼 있어야 합니다.
if ('예제'.Length -ne 2 -or '개념'.Length -ne 2) {
    throw @"
이 스크립트의 한글이 깨진 채로 읽혔습니다 (인코딩 문제).
이 파일은 UTF-8 BOM 으로 저장돼 있어야 합니다.

  git pull        로 최신 버전을 받아 다시 실행해 보세요.

그래도 안 되면 PowerShell 7 로 실행하세요:
  winget install Microsoft.PowerShell
  pwsh -File .\tools\migrate-local-vault.ps1 ...
"@
}

if (-not (Test-Path (Join-Path $Vault '.git'))) {
    throw "볼트가 git 리포지터리가 아닙니다: $Vault"
}

# 옮기지 말아야 할 것들 — 새 볼트에 이미 루트 버전이 있습니다.
$Skip = @('.git', '.vscode', '.obsidian', 'node_modules')

function Copy-Into {
    param([string]$Source, [string]$Destination, [string]$Label)

    if ([string]::IsNullOrWhiteSpace($Source)) { return }
    if (-not (Test-Path $Source)) {
        Write-Host "건너뜀 ($Label): 경로 없음 — $Source" -ForegroundColor Yellow
        return
    }

    if (-not (Test-Path $Destination)) {
        if ($PSCmdlet.ShouldProcess($Destination, '폴더 생성')) {
            New-Item -ItemType Directory -Path $Destination -Force | Out-Null
        }
    }

    $items = Get-ChildItem -Path $Source -Force |
             Where-Object { $Skip -notcontains $_.Name }

    Write-Host "$Label : $Source  →  $Destination  ($($items.Count)개 항목)" -ForegroundColor Cyan
    foreach ($item in $items) {
        $target = Join-Path $Destination $item.Name
        if (Test-Path $target) {
            Write-Host "  · 이미 존재하여 건너뜀: $($item.Name)" -ForegroundColor DarkYellow
            continue
        }
        if ($PSCmdlet.ShouldProcess($target, '복사')) {
            Copy-Item -Path $item.FullName -Destination $target -Recurse -Force
            Write-Host "  + $($item.Name)" -ForegroundColor Green
        } else {
            Write-Host "  + $($item.Name)  (미리보기)" -ForegroundColor DarkGray
        }
    }
}

Copy-Into -Source $CppNotes       -Destination (Join-Path $Vault 'C++\개념')    -Label 'C++ 개념'
Copy-Into -Source $CppProjects    -Destination (Join-Path $Vault 'C++\예제')    -Label 'C++ 예제'
Copy-Into -Source $PythonNotes    -Destination (Join-Path $Vault 'Python\개념') -Label 'Python 개념'
Copy-Into -Source $PythonProjects -Destination (Join-Path $Vault 'Python\예제') -Label 'Python 예제'

Write-Host ''
Write-Host '완료. 이제 아래로 확인한 뒤 커밋하세요:' -ForegroundColor Cyan
Write-Host "  cd `"$Vault`""
Write-Host '  git status'
Write-Host '  powershell -ExecutionPolicy Bypass -File tools\auto-sync.ps1 -Once'
