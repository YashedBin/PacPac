@echo off

if not exist build-win mkdir build-win
cd build-win

cmake .. -G "Visual Studio 17 2022" -A x64
cmake --build . --config Release

cd ..
build-win\bin\Release\pacpac.exe