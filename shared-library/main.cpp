#include <iostream>
#include <string>
#include "Flight.h"
#include "AirportFlights.h"

using namespace std;

vector<AirportFlights> getDatabase();
void getFlightsFromFile(AirportFlights &airport, ifstream &file);

int main() {
    vector<AirportFlights> database = getDatabase();



    return 0;
}


/**
 * Get the flights for each airport in the 'flightsDB' folder.
 * (from arrival and departure files of each airport)
 */
vector<AirportFlights> getDatabase() {
    vector<AirportFlights> res;

    path parent_path = current_path().parent_path().parent_path();
    parent_path += "/flightsDB";

    string curr_path;
    string curr_name;

    // Run through all the directories in the airports database.
    for (const auto& entry : directory_iterator(parent_path)) {
        if (entry.is_directory()) {
            curr_path = entry.path();

            // Get the last 4 characters of the current path (the name of the airport).
            curr_name = curr_path;
            curr_name = curr_name.substr(curr_name.size() - 4);

            // Get the path to the arrival and departure files.
            string file_arrival_path = curr_path + "/" + curr_name + ".arv";
            string file_departure_path = curr_path + "/" + curr_name + ".dpt";

            // Open the files to receive data.
            ifstream file_arrival(file_arrival_path);
            ifstream file_departure(file_departure_path);

            // Get the flights of the current airport.
            AirportFlights currAirport(curr_name);
            getFlightsFromFile(currAirport, file_arrival);
            getFlightsFromFile(currAirport, file_departure);

            // Done receiving data from files. closing them...
            file_arrival.close();
            file_departure.close();

            res.push_back(currAirport);
        }
    }

    return res;
}

void getFlightsFromFile(AirportFlights &airport, ifstream &file)
{
    Flight currFlight;
    string currLine;

    getline(file, currLine); // Read the first line to skip the header.

    while(getline(file, currLine)) {
        // create a stringstream from the current line.
        stringstream ss(currLine);
        string currField;

        // Go through each field separated by commas.
        getline(ss, currField, ','); // Get ICAO24.
        currFlight.setIcao24(currField);

        getline(ss, currField, ','); // Get firstSeen.
        currFlight.setFirstSeen(stoi(currField));

        getline(ss, currField, ','); // Get estDepartureAirport.
        currFlight.setEstDepartureAirport(currField);

        getline(ss, currField, ','); // Get lastSeen.
        currFlight.setLastSeen(stoi(currField));

        getline(ss, currField, ','); // Get estArrivalAirport.
        currFlight.setEstArrivalAirport(currField);

        getline(ss, currField, ','); // Get callsign.
        currFlight.setCallsign(currField);

        // add currFlight into the airport's flights.
        airport.addFlight(currFlight);

        cout << "Successfully received flight: " << flush;
        currFlight.print();
    }
}
