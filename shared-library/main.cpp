#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

int main() {
    vector<AirportFlights> database = AirportFlights::getDatabase();
    Functions::rerunBashScript(database);
    return 0;
}
