#include "Database.h"

void Database::getDB() {
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

            // Open the files.
            ifstream file_arrival(file_arrival_path);
            ifstream file_departure(file_departure_path);
        }
    }
}
