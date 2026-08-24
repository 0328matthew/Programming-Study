param(
    [Parameter(Mandatory = $true)][string]$Source,
    [string]$Mode = "ask"
)

# VS Code 태스크에서 호출되는 C/C++ 빌드·실행 래퍼.
# 컴파일러는 MSYS2 UCRT64 로 고정한다 (PATH 에 무엇이 있든 무시).

$ErrorActionPreference = "Stop"
[Console]::OutputEncoding = [System.Text.Encoding]::GetEncoding(949)

if ($Mode -eq "ask") {
    $ans = Read-Host "빌드하고 실행할까요? (Y/n)"
    if ($ans -match '^[Nn]') {
        Write-Host "[취소] 아무 작업도 하지 않았습니다."
        exit 1
    }
    $Mode = "build-run"
}

if ($Mode -eq "cancel") {
    Write-Host "[취소] 아무 작업도 하지 않았습니다."
    exit 1
}

$dir  = Split-Path -Parent $Source
$name = [System.IO.Path]::GetFileNameWithoutExtension($Source)
$ext  = [System.IO.Path]::GetExtension($Source).ToLower()
$exe  = Join-Path $dir "$name.exe"

if ($ext -eq ".c") {
    $compiler = "C:/msys64/ucrt64/bin/gcc.exe"
    $stdFlag  = "-std=c17"
} else {
    $compiler = "C:/msys64/ucrt64/bin/g++.exe"
    $stdFlag  = "-std=c++20"
}

if (-not (Test-Path $compiler)) {
    Write-Host "[오류] 컴파일러가 없습니다: $compiler"
    exit 1
}

if ($Mode -ne "run-only") {
    Write-Host "[빌드] $compiler $stdFlag -Wall -Wextra"
    & $compiler -g -Wall -Wextra $stdFlag $Source -o $exe
    if ($LASTEXITCODE -ne 0) {
        Write-Host "[실패] 컴파일 오류 (exit $LASTEXITCODE)"
        exit $LASTEXITCODE
    }
    Write-Host "[성공] $exe"
}

if ($Mode -eq "build-only") { exit 0 }

if (-not (Test-Path $exe)) {
    Write-Host "[오류] 실행 파일이 없습니다: $exe"
    exit 1
}

Write-Host ""
Write-Host "----- 실행 -----"
Push-Location $dir
& $exe
$code = $LASTEXITCODE
Pop-Location
Write-Host "----- 종료 코드: $code -----"
exit 0
