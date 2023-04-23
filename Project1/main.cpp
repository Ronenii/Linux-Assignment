#include <iostream>
#include "Flight.h"
#include "AirportFlights.h"
#include "Functions.h"

int main(int args, char*argv[]) {
    std::cout << "Hello, World!" << std::endl;
    vector<AirportFlights> DB = AirportFlights::getDatabase();
    return 0;
}
