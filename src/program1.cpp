#include <iostream>
#include "../lib/AirportFlights.h"

void printFlights(const vector<Flight>& flights);

int program1(int argc, char* argv[]) {
    vector<AirportFlights> DB = AirportFlights::getDatabase();
    vector<Flight> arrivals;

    // For every airport received:
    for (int i = 1; i < argc; ++i) {
        for(auto& airport: DB) {            // Find that airport in the database.
            if(argv[i] == airport.getAirportName()) {    // Found the airport
                arrivals = airport.getArrivals();        // Get the arrival flights for the airport.
                printFlights(arrivals);            // Print arrival flights.
                break;
            }
        }
    }
    return 0;
}

/**
 * Print flights within a vector.
 */
void printFlights(const vector<Flight>& flights) {
    for(auto & flight: flights) {
        cout<< "Flight " << flight.getCallsign() << " arriving from " << flight.getEstDepartureAirport()
        << ", tookoff at " << flight.getFirstSeen() << " landed at " << flight.getLastSeen() << endl;
    }
}