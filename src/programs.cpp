#include <iostream>
#include "../lib/AirportFlights.h"
#include "programs.h"
#include <string>
#include "../lib/Functions.h"
#include <vector>


void printFlights(const vector<Flight>& flights);

void program1(int argc, char* argv[]) {
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


// ---------------------------------------------------------------------------------------


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


void program2(int argc, char *argv[]) {
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
}


// ---------------------------------------------------------------------------------------


void printFlightsWithICAO24(vector<AirportFlights> &DB, const string& icao24);
void printFlight(const Flight& flight);
void runOnFlightsList(vector<Flight> &flights, const string& icao24);

void program3(int argc, char* argv[]) {
    vector<AirportFlights> DB = AirportFlights::getDatabase();

    for(int i=1; i<argc;i++) {
        printFlightsWithICAO24(DB,argv[i]);
    }
}

void printFlightsWithICAO24(vector<AirportFlights> &DB, const string& icao24) {
    vector<Flight> flights;

    for(auto& airport: DB) {
        flights = airport.getDepartures();
        runOnFlightsList(flights,icao24);
        flights = airport.getArrivals();
        runOnFlightsList(flights,icao24);
    }
}

void runOnFlightsList(vector<Flight> &flights, const string& icao24) {
    for(auto& flight: flights) {
        if(flight.getIcao24() == icao24)
            printFlight(flight);
    }
}

void printFlight(const Flight& flight) {
    cout<<flight.getIcao24()<<" departed from "<<flight.getEstDepartureAirport()<<" at "<<flight.getFirstSeen()
        <<" arrived in "<<flight.getEstArrivalAirport()<<" at "<<flight.getLastSeen()<<endl;
}


// ---------------------------------------------------------------------------------------


void program4() {
    vector<AirportFlights> DB = AirportFlights::getDatabase();
    Functions::updateDatabase(DB);
}

