@echo off
setlocal
cd /d "%~dp0"

powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0build.ps1" %*
set ERR=%ERRORLEVEL%

if not %ERR%==0 (
    echo.
    echo Build failed with exit code %ERR%.
    pause
    exit /b %ERR%
)

echo.
echo Build finished successfully.
pause
exit /b 0
