#ifndef SHARED_LIBRARY_DATABASE_H
#define SHARED_LIBRARY_DATABASE_H

#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
#include "Flight.h"

using namespace std;
using namespace filesystem;

class Database {
    vector<Flight> flights;

public:
    void getDB();

};


#endif //SHARED_LIBRARY_DATABASE_H
