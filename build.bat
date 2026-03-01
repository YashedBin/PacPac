@echo off
REM Batch for building Client 
REM Windows is so different

REM Creates obviously a Build Directory 
if not exist build-win mkdir build-win
cd build-win


cmake .. -G "Visual Studio 17 2022" -A x64

cmake --build . --config Release

REM Running the Exec
REM pacpac.exe
