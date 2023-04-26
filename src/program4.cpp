#include <iostream>
#include <string>
#include <cstdlib>
#include "../lib/Functions.h"
#include "../lib/Flight.h"
#include "../lib/AirportFlights.h"

int main(int argc, char* argv[]) {
    char* program_path = realpath(argv[0], nullptr);

    if(program_path == nullptr){ // Check for errors in receiving path.
        cout << "Error: could not receive the program's path!" << endl;
        return 1;
    }
    string path = program_path; // Convert to string.

    // Find the position of the last '/' character.
    size_t pos = path.find_last_of('/');
    if(pos != string::npos) {
        // Update to path to remove the excess characters.
        path = path.substr(0, pos);
    }
    else {
        cout << "Error: could not find index of '/'" << endl;
        return 1;
    }

    // Add the script name to the path.
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
