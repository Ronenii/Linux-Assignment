#include "Functions.h"

vector<Flight> Functions::getFlightsByAirportName(string airportName, vector<AirportFlights> &DB)
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

vector<Flight> Functions::getArrivalsByAirportName(string airportName, vector<AirportFlights> &DB)
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

vector<Flight> Functions::getFlightsByCallsign(string callsign, vector<AirportFlights> &DB)
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

void Functions::rerunBashScript(vector<AirportFlights> &DB)
{
    path parent_path = current_path().parent_path().parent_path() / "script.sh";
    string command = parent_path.string();
    addAirportNamesToStr(command,DB);
    string script_dir = parent_path.parent_path().string();
    chdir(script_dir.c_str());
    command = "bash " + command;
    std::system(command.c_str());
}

void Functions::addAirportNamesToStr(string& path, vector<AirportFlights> &DB)
{
    for(const auto& airport : DB)
    {
        path = path + " " + airport.getAirportName();
    }
}

void Functions::pushFlights(const vector<Flight> &src, vector<Flight> &dst)
{
    for(const auto& flight: src)
    {
        dst.push_back(flight);
    }
}

void Functions::pushFlightsByCallsign(const vector<Flight> &src, vector<Flight> &dst, string callsign)
{
    for(const auto& flight: src)
    {
        if(flight.getCallsign() == callsign)
        {
            dst.push_back(flight);
        }
    }
}
