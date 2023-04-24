#include <iostream>
#include <string>
#include <cstdlib>
#include "Functions.h"
#include "Flight.h"
#include "AirportFlights.h"

int main(int argc, char* argv[]) {
    char* program_path = realpath(argv[0], nullptr);

    if(program_path == nullptr){ // Check for errors in receiving path.
        cout << "Error: could not receive the program's path!" << endl;
        return 1;
    }

    string path = program_path;
    path += "/script.sh";

    for (int i = 1; i < argc; ++i) { // Add airports to the path.
        path += " " + (string)argv[i];
    }

    // Run the script.
    int status = system(path.c_str());

    if(status != 0) { // Error running the script.
        cout << "Error: cannot run the script with the path provided!" << endl;
        return 1;
    }

    return 0;
}
