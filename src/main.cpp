#include <iostream>
#include <stdlib.h>

using namespace std;

enum class MenuOptions{
    FetchAirportsIncomingFlights = 1,
    FetchAirportsFullFlightSchedule,
    FetchAircraftsFullFlightSchedule,
    UpdateDatabase,
    ZipDatabaseFiles,
    GetChildProcessID,
    GracefulExit
};

void printMenu();
int program1(int argc, char* argv[]);
int program2(int argc, char *argv[]);
int program3(int argc, char* argv[]);
int program4();

int main(int argc, char *argv[]) {
    MenuOptions choice;

    do {
        system("cls"); // Clear CLI
        int token;
        printMenu();
        cin >> token;
        choice = static_cast<MenuOptions>(token);

        switch(choice) {
            case MenuOptions::FetchAirportsIncomingFlights:
                program1(argc, argv);
                break;
            case MenuOptions::FetchAirportsFullFlightSchedule:
                program2(argc, argv);
                break;
            case MenuOptions::FetchAircraftsFullFlightSchedule:
                program3(argc, argv);
                break;
            case MenuOptions::UpdateDatabase:
                program4();
                break;
            case MenuOptions::ZipDatabaseFiles:

                break;
            case MenuOptions::GetChildProcessID:

                break;
            case MenuOptions::GracefulExit:

                break;
            default:
                cout << "Error: Wrong input received. Please re-choose a menu option." << endl;

        }

    }
    while(choice != MenuOptions::GracefulExit);

}

void printMenu() {
    cout << "**************************" << endl <<
    "1. Fetch Airports Incoming Flights" << endl <<
    "2. Fetch Airports Full Flights Schedule" << endl <<
    "3. Fetch Aircrafts Full Flights Schedule" << endl <<
    "4. Update Database" << endl <<
    "5. Zip Database Files" << endl <<
    "6. Get Child PID" << endl <<
    "7. Exit" << endl;
}