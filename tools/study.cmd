@echo off
REM 더블클릭으로 볼트를 열고, 창을 닫으면 자동 커밋·푸시합니다.
REM 바로가기를 만들어 작업표시줄에 고정해 두면 편합니다.
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0study.ps1"
