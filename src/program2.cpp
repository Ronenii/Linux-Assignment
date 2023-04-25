#include <iostream>
#include <algorithm>
#include <string>
#include "../shared-library/Flight.h"
#include "../shared-library/Functions.h"
#include "../shared-library/AirportFlights.h"

/**
 * Compare two flights by the time of arrival/departure to/from a given airport.
 */
bool compareFlights(const Flight &f1, const Flight &f2, const string &airport_name) {
    int time_f1, time_f2;

    if(f1.getEstArrivalAirport() == airport_name)
        time_f1 = f1.getLastSeen();
    else
        time_f1 = f1.getFirstSeen();

    if(f2.getEstArrivalAirport() == airport_name)
        time_f2 = f2.getLastSeen();
    else
        time_f2 = f2.getFirstSeen();

    return time_f1 < time_f2;
}


int main(int argc, char *argv[]) {
    string airport_name = argv[1];

    // Get the database from the files:
    vector<AirportFlights> database = AirportFlights::getDatabase();

    // Get all flights of received airport:
    vector<Flight> airport_flights = Functions::getFlightsByAirportName(airport_name, database);

    // Bubble sort the vector using the compareFlights function:
    for (int i = 0; i < airport_flights.size() - 1; ++i) {
        for (int j = i + 1; j < airport_flights.size(); ++j) {
            if(!compareFlights(airport_flights[i], airport_flights[j], airport_name))
                swap(airport_flights[i], airport_flights[j]);
        }
    }

    // Print sorted flights details:
    for(Flight& curr : airport_flights) {
        if(curr.isArriving(airport_name))  // Arriving to received airport.
            cout << "Flight " << curr.getCallsign() << " arriving from " << curr.getEstDepartureAirport() << " at " << curr.getTime(airport_name) << endl;
        else                                   // Departing from received airport.
            cout << "Flight " << curr.getCallsign() << " departing to " << curr.getEstArrivalAirport() << " at " << curr.getTime(airport_name) << endl;
    }
    return 0;
}
