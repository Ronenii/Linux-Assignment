#!/bin/bash

g++ -c -fPIC shared_library/Functions.cpp -o objects/Functions.o
g++ -c -fPIC shared_library/AirportFlights.cpp -o objects/AirportFlights.o
g++ -c -fPIC shared_library/Flight.cpp -o objects/Flight.o

g++ -shared -fPIC -o objects/libshared_library.so objects/Functions.o objects/AirportFlights.o objects/Flight.o 

g++ -o program1.out src/program1.cpp -I/shared_library -L/objects -lshared_library
g++ -o program2.out src/program2.cpp -Iobjects/libshared_library.so
g++ -o program3.out src/program3.cpp -Iobjects/libshared_library.so
g++ -o program4.out src/program4.cpp -Iobjects/libshared_library.so