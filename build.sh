#!/bin/bash

#cd client

mkdir -p build-lin
cd build-lin


cmake ..

make -j$(nproc)
cd bin

./pacpac
