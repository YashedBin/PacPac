#!/bin/bash

#cd client

mkdir -p build
cd build

cmake ..

make -j$(nproc)

./client/pacpac
