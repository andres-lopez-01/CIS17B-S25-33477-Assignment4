#pragma once
#include <string>;

using namespace std;

class StoredItem {
private:
    string id;
    string description;
    string location;

public:
    StoredItem(string id, string desc, string loc)
        : id(id), description(desc), location(loc) {}

    string getId() const; //returns string Id
    string getDescription() const; //returns description
    string getLocation() const; //returns location
};

