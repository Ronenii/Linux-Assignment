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
private:
    const string name;
    vector<Flight> arrivals;
    vector<Flight> departures;
public:
    const vector<Flight> &getArrivals() const {
        return arrivals;
    }

    void setArrivals(const vector<Flight> &arrivals) {
        AirportFlights::arrivals = arrivals;
    }

    const vector<Flight> &getDepartures() const {
        return departures;
    }

    void setDepartures(const vector<Flight> &departures) {
        AirportFlights::departures = departures;
    }

public:
    explicit AirportFlights(const string &_name) : name(_name) {}
    void addArrivalFlight(const Flight &_flight) { arrivals.push_back(_flight); }
    void addDepartureFlight(const Flight &_flight) { departures.push_back(_flight); }
    const string getAirportName() const {return name;}

};


#endif //SHARED_LIBRARY_AIRPORTFLIGHTS_H
