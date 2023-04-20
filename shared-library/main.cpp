#include <iostream>
#include <string>
#include "Flight.h"
#include "AirportFlights.h"
#include <unistd.h>

using namespace std;

vector<AirportFlights> getDatabase();
void getFlightsFromFile(AirportFlights &airport, ifstream &file, bool flightStatus);
vector<Flight> getFlightsByAirportName(string airportName, vector<AirportFlights> &DB);
void pushFlights(const vector<Flight> &src, vector<Flight> &dst);
vector<Flight> getArrivalsByAirportName(string airportName, vector<AirportFlights> &DB);
void pushFlightsByCallsign(const vector<Flight> &src, vector<Flight> &dst, string callsign);
void rerunBashScript(vector<AirportFlights> &DB);
void addAirportNamesToStr(string& path, vector<AirportFlights> &DB);

int main() {
    vector<AirportFlights> database = getDatabase();
    rerunBashScript(database);


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
            getFlightsFromFile(currAirport, file_arrival, true);
            getFlightsFromFile(currAirport, file_departure, false);

            // Done receiving data from files. closing them...
            file_arrival.close();
            file_departure.close();

            res.push_back(currAirport);
        }
    }

    return res;
}

/*flightStatus: true value stands for arrivals flights, false value for departures. */
void getFlightsFromFile(AirportFlights &airport, ifstream &file, bool flightStatus)
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
        if(flightStatus)
        {
            airport.addArrivalFlight(currFlight);
        }
        else
        {
            airport.addDepartureFlight(currFlight);
        }

        cout << "Successfully received flight: " << flush;
        currFlight.print();
    }
}

vector<Flight> getFlightsByAirportName(string airportName, vector<AirportFlights> &DB)
{
    vector<Flight> res;
    for(const auto& airport : DB)
    {
        if(airport.getAirportName() == airportName)
        {
            pushFlights(airport.getArrivals(), res);
            pushFlights(airport.getDepartures(), res);
            break;
        }
    }
    return res;
}

vector<Flight> getArrivalsByAirportName(string airportName, vector<AirportFlights> &DB)
{
    vector<Flight> res;
    for(const auto& airport : DB)
    {
        if(airport.getAirportName() == airportName)
        {
            pushFlights(airport.getArrivals(), res);
            break;
        }
    }
    return res;
}

vector<Flight> getFlightsByCallsign(string callsign, vector<AirportFlights> &DB)
{
    vector<Flight> res, currAirport;
    for(const auto& airport : DB)
    {
        currAirport = airport.getArrivals();
        pushFlightsByCallsign(currAirport,res,callsign);
        currAirport = airport.getDepartures();
        pushFlightsByCallsign(currAirport,res,callsign);
    }
    return res;
}

void rerunBashScript(vector<AirportFlights> &DB)
{

    path parent_path = current_path().parent_path().parent_path() / "script.sh";
    string command = parent_path.string();
    addAirportNamesToStr(command,DB);
    string script_dir = parent_path.parent_path().string();
    chdir(script_dir.c_str());
    command = "bash " + command;
    std::system(command.c_str());
}

void addAirportNamesToStr(string& path, vector<AirportFlights> &DB)
{
    for(const auto& airport : DB)
    {
        path = path + " " + airport.getAirportName();
    }
}

void pushFlights(const vector<Flight> &src, vector<Flight> &dst)
{
    for(const auto& flight: src)
    {
        dst.push_back(flight);
    }
}

void pushFlightsByCallsign(const vector<Flight> &src, vector<Flight> &dst, string callsign)
{
    for(const auto& flight: src)
    {
        if(flight.getCallsign() == callsign)
        {
            dst.push_back(flight);
        }
    }
}
