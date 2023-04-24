#include <iostream>
#include <string>
#include "AirportFlights.h"
#include "Flight.h"
#include "Functions.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<AirportFlights> DB = AirportFlights::getDatabase();
    vector<Flight> arrivals;
    string input;
    cin >> input;

    for(auto& airport: DB)
    {
        if(input == airport.getAirportName()) {
            arrivals = airport.getArrivals();
            break;
        }
    }
    for(auto & flight: arrivals)
    {
        cout << "Flight " << flight.getCallsign() << " arriving from " << flight.getEstDepartureAirport() << ", took off at " << "TIME" << " landed at " << "TIME";
    }
    return 0;
}
