#!/bin/bash

g++ -c -fPIC lib/Functions.cpp -o objects/Functions.o
g++ -c -fPIC lib/AirportFlights.cpp -o objects/AirportFlights.o
g++ -c -fPIC lib/Flight.cpp -o objects/Flight.o
g++ -c -fPIC src/program1.cpp -o objects/program1.o
g++ -c -fPIC src/program2.cpp -o objects/program2.o
g++ -c -fPIC src/program3.cpp -o objects/program3.o
g++ -c -fPIC src/program4.cpp -o objects/program4.o

g++ -shared -fPIC -o objects/libshared_library.so objects/Functions.o objects/AirportFlights.o objects/Flight.o

g++ src/program1.cpp -o program1.out -I./lib -L. -lshared_library
g++ src/program2.cpp -o program2.out -I./lib -L. -lshared_library
g++ src/program3.cpp -o program3.out -I./lib -L. -lshared_library
g++ src/program4.cpp -o program4.out -I./lib -L. -lshared_library

# add current directory to the library path- where it will search for external libraries.
LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$PWD"
export LD_LIBRARY_PATH

# run the program from here. you can't run the program from outside the script because the LD_LIBRARY PATH
# is only set for the current program and not outside of it. it is possible to run the above command
# without the export to use it outside of this script's scope.
# Added a README file that explains this issue, so that we dont need to add to the library path from here.
./program1.out