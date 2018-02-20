Configure:
In scripts/conf.sh change CC and CXX variable for example:
	export CC='../tool/minGW-5.3.0/bin/gcc.exe'
	export CXX='../tool/minGW-5.3.0/bin/g++.exe'
where ../tool/minGW-5.3.0/bin/gcc.exe is path to mingw gcc.exe compiler on your PC

Afret that run in command line:
./scripts/conf.sh


To make Makefile with cmake run from build folder:
cmake ..

Compiling from build folder:
make all

Run: 
/src/pad.exe


Compiling SFML library (Optional):
in folder build-SFML run:
mingw32-make instal

