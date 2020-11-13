@echo off
gcc main.c scan.c convmed.c -o APS_TC.exe

if "%~1"=="-r" start APS_TC.exe
:end

if "%~1"=="?" echo -r: Compilar e executar programa