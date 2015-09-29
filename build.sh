#!/bin/sh

mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/Toolchain/simbol100.tcm ..
make