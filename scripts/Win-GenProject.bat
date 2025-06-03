@echo off
:choose_option
echo Please select a build system:
echo 1. Visual Studio 2022
echo 2. Visual Studio 2019
echo 3. GMake
set /p choice=Enter your choice (1/2/3):

REM Validate input
if "%choice%"=="1" goto vs2022
if "%choice%"=="2" goto vs2019
if "%choice%"=="3" goto gmake
echo Invalid choice, please try again.
goto choose_option

:vs2022
pushd ..\
call vendor\premake\premake5.exe vs2022
popd
IF %ERRORLEVEL% NEQ 0 (
  PAUSE
)
goto end

:vs2019
pushd ..\
call vendor\premake\premake5.exe vs2019
popd
IF %ERRORLEVEL% NEQ 0 (
  PAUSE
)
goto end

:gmake
pushd ..\
call vendor\premake\premake5.exe gmake
popd
IF %ERRORLEVEL% NEQ 0 (
  PAUSE
)
goto end

:end