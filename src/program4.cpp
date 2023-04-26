#include <iostream>
#include <string>
#include <cstdlib>
#include "../lib/Functions.h"
#include "../lib/Flight.h"
#include "../lib/AirportFlights.h"

int main() {
    vector<AirportFlights> DB = AirportFlights::getDatabase();
    Functions::updateDatabase(DB);
}
