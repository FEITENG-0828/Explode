@echo off
REM 清理build目录
set BUILD_DIR=build

if exist %BUILD_DIR% (
    echo ====== Cleaning build directory... ======
    rmdir /s /q %BUILD_DIR%
    echo ====== Build directory cleaned. ======
) else (
    echo ====== Build directory does not exist, no need to clean. ======
)

pause
