#include <iostream>
#include <string>
#include <cstdlib>
#include "../lib/Functions.h"
#include "../lib/Flight.h"
#include "../lib/AirportFlights.h"

int program4() {
    vector<AirportFlights> DB = AirportFlights::getDatabase();
    Functions::updateDatabase(DB);
}
