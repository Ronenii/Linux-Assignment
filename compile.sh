#!/bin/bash

g++ -c -fPIC shared_library/Functions.cpp -o objects/Functions.o
g++ -c -fPIC shared_library/AirportFlights.cpp -o objects/AirportFlights.o
g++ -c -fPIC shared_library/Flight.cpp -o objects/Flight.o

g++ -shared -fPIC -o objects/libshared_library.so objects/Functions.o objects/AirportFlights.o objects/Flight.o 


