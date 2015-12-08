#!/bin/sh
rm -r build_rosa
mkdir build_rosa
cd build_rosa
cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/Toolchain/simbol100.tcm ..
make
