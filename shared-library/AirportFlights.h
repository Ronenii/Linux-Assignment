#ifndef SHARED_LIBRARY_AIRPORTFLIGHTS_H
#define SHARED_LIBRARY_AIRPORTFLIGHTS_H

#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
#include "Flight.h"

using namespace std;
using namespace filesystem;

class AirportFlights {
    const string name;
    vector<Flight> flights;

public:
    explicit AirportFlights(const string &_name) : name(_name) {}
    void addFlight(const Flight &_flight) { flights.push_back(_flight); }

};


#endif //SHARED_LIBRARY_AIRPORTFLIGHTS_H
