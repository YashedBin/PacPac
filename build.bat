@echo off
REM Batch for building Client 
REM Windows is so different

cd client

REM Creates obviously a Build Directory 
if not exist build mkdir build
cd build


cmake ..

cmake --build . --config Release

REM Running the Exec
REM pacpac.exe
