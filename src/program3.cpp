#include <iostream>
#include "Flight.h"
#include "AirportFlights.h"
#include <vector>

void printFlightsWithICAO24(vector<AirportFlights> &DB, string icao24);
void printFlight(Flight flight);
void runOnFlightsList(vector<Flight> &flights, string icao24);

int main(int argc, char* argv[]) {
    vector<AirportFlights> DB = AirportFlights::getDatabase();
    for(int i=1; i<argc;i++)
    {
        printFlightsWithICAO24(DB,argv[i]);
    }
    return 0;
}

void printFlightsWithICAO24(vector<AirportFlights> &DB, string icao24)
{
    vector<Flight> flights;
    for(auto& airport: DB)
    {
        flights = airport.getDepartures();
        runOnFlightsList(flights,icao24);
        flights = airport.getArrivals();
        runOnFlightsList(flights,icao24);
    }
}

void runOnFlightsList(vector<Flight> &flights, string icao24)
{
    for(auto& flight: flights)
    {
        if(flight.getIcao24() == icao24)
        {
            printFlight(flight);
        }
    }
}

void printFlight(Flight flight)
{
    cout<<flight.getIcao24()<<" departed from "<<flight.getEstDepartureAirport()<<" at "<<flight.getFirstSeen()
    <<" arrived in "<<flight.getEstArrivalAirport()<<" at "<<flight.getLastSeen()<<endl;
}