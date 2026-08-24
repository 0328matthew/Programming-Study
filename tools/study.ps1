<#
.SYNOPSIS
    볼트를 VS Code 로 열고, 창을 닫는 순간 커밋·푸시합니다.

.DESCRIPTION
    VS Code 에는 "닫힐 때" 실행되는 훅이 없습니다. 대신 code --wait 는 창이
    닫힐 때까지 반환하지 않으므로, 그 뒤에 동기화를 붙이면 사실상
    "닫으면 푸시"가 됩니다.

    tools/auto-sync.ps1 의 유휴 감지 동기화가 이미 대부분을 처리하지만,
    이 래퍼는 마지막 한 글자까지 확실히 올라가게 해 줍니다.

.EXAMPLE
    powershell -ExecutionPolicy Bypass -File tools\study.ps1

.NOTES
    PowerShell 프로필에 함수로 등록해 두면 편합니다. 자세한 내용은
    docs/자동-푸시-설정.md 를 보세요.
#>

[CmdletBinding()]
param(
    # 이 스크립트가 tools/ 안에 있으므로 기본값은 그 상위 폴더(볼트 루트)입니다.
    [string]$VaultPath = (Split-Path -Parent $PSScriptRoot)
)

$ErrorActionPreference = 'Stop'

if (-not (Test-Path (Join-Path $VaultPath '.git'))) {
    Write-Host "git 리포지터리가 아닙니다: $VaultPath" -ForegroundColor Red
    exit 1
}

Set-Location $VaultPath

# 열기 전에 원격 변경사항을 먼저 받아 둡니다 (다른 기기에서 편집했을 수 있음).
Write-Host '원격 변경사항 확인 중...' -ForegroundColor DarkGray
& git pull --rebase --autostash
if ($LASTEXITCODE -ne 0) {
    Write-Host 'pull 에 실패했습니다. 충돌을 먼저 해결하세요.' -ForegroundColor Red
    exit 1
}

Write-Host 'VS Code 를 엽니다. 창을 닫으면 자동으로 커밋·푸시합니다.' -ForegroundColor Cyan
& code --wait $VaultPath

Write-Host '창이 닫혔습니다 — 최종 동기화 중...' -ForegroundColor Cyan
& powershell -NoProfile -ExecutionPolicy Bypass `
    -File (Join-Path $PSScriptRoot 'auto-sync.ps1') `
    -VaultPath $VaultPath -Once
