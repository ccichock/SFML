#!/bin/bash

alias cmake='../tool/cmake/bin/cmake -G "MinGW Makefiles"'
alias make='mingw32-make'

export CC='../tool/minGW-5.3.0/bin/gcc.exe'
export CXX='../tool/minGW-5.3.0/bin/g++.exe'

mkdir -p build
cd build