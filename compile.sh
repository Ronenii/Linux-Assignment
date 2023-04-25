#!/bin/bash

g++ -c -fPIC lib/Functions.cpp -o objects/Functions.o
g++ -c -fPIC lib/AirportFlights.cpp -o objects/AirportFlights.o
g++ -c -fPIC lib/Flight.cpp -o objects/Flight.o
g++ -c -fPIC src/program1.cpp -o objects/program1.o
g++ -c -fPIC src/program2.cpp -o objects/program2.o
g++ -c -fPIC src/program3.cpp -o objects/program3.o
g++ -c -fPIC src/program4.cpp -o objects/program4.o


g++ -shared -fPIC -o objects/libshared_library.so objects/Functions.o objects/AirportFlights.o objects/Flight.o 


g++ src/program1.cpp -o program1.out -I./lib -L./objects -lshared_library
g++ src/program3.cpp -o program3.out -I./lib -L./objects -lshared_library

