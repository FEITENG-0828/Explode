@echo off
REM 设置项目根目录
set PROJECT_ROOT=%cd%

REM 创建并进入 build 目录
if not exist build mkdir build
cd build

REM 运行 CMake 配置
echo ====== Configuring project with CMake... ======
cmake .. -G "MinGW Makefiles"
if %ERRORLEVEL% neq 0 (
    echo ====== CMake configuration failed! ======
    pause
    exit /b 1
)

REM 构建项目
echo ====== Building project... ======
mingw32-make
if %ERRORLEVEL% neq 0 (
    echo ====== Build failed! ======
    pause
    exit /b 1
)

REM 返回到项目根目录
cd %PROJECT_ROOT%

pause
