#ifndef SHARED_LIBRARY_FUNCTIONS_H
#define SHARED_LIBRARY_FUNCTIONS_H

#include "AirportFlights.h"
#include "Flight.h"
#include <unistd.h>

class Functions {
public:
    static vector<Flight> getFlightsByAirportName(string airportName, vector<AirportFlights> &DB);
    static void pushFlights(const vector<Flight> &src, vector<Flight> &dst);
    static vector<Flight> getArrivalsByAirportName(string airportName, vector<AirportFlights> &DB);
    static vector<Flight> getFlightsByCallsign(string callsign, vector<AirportFlights> &DB);
    static void pushFlightsByCallsign(const vector<Flight> &src, vector<Flight> &dst, string callsign);
    static void rerunBashScript(vector<AirportFlights> &DB);
    static void addAirportNamesToStr(string& path, vector<AirportFlights> &DB);

};



#endif //SHARED_LIBRARY_FUNCTIONS_H
