#include <iostream>
#include "../lib/AirportFlights.h"
#include "../lib/Functions.h"
#include "../lib/Flight.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<AirportFlights> DB = AirportFlights::getDatabase();
    vector<Flight> arrivals;
    string input;
    cin >> input;

    for(auto & airport: DB)
    {
        if(input == airport.getAirportName())
        {
            arrivals = airport.getArrivals();
            break;
        }
    }
    for(auto & flight: arrivals)
    {
        cout<< "Flight " << flight.getCallsign() << " arriving for " << flight.getEstDepartureAirport() << ", tookoff at " << flight.getFirstSeen() << " landed at " << flight.getLastSeen() << endl;
    }


    return 0;
}
