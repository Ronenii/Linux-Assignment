#!/bin/bash

g++ -c -fPIC shared_library/Functions.cpp -o objects/Functions.o
g++ -c -fPIC shared_library/AirportFlights.cpp -o objects/AirportFlights.o
g++ -c -fPIC shared_library/Flight.cpp -o objects/Flight.o

g++ -shared -fPIC -o objects/libshared_library.so objects/Functions.o objects/AirportFlights.o objects/Flight.o 


g++ src/program1.cpp -o program1.out -I/shared_library -L/objects -lshared_library
g++ src/program3.cpp -o program3.out -I/shared_library -L/objects -lshared_library

