#ifndef SHARED_LIBRARY_DATABASE_H
#define SHARED_LIBRARY_DATABASE_H

#include <vector>
#include <string>
#include <fstream>
#include "Flight.h"

using namespace std;

class Database {
    vector<Flight> flights;

public:
    void getDB();

};


#endif //SHARED_LIBRARY_DATABASE_H
