#pragma once
#include "StoredItem.h"
#include <iostream>
#include <unordered_map>
#include <map>
#include <memory>

using namespace std;

class StorageManager {
private:
    unordered_map<string, shared_ptr<StoredItem>> itemById;
    map<string, shared_ptr<StoredItem>> itemByDescription;

public:
    void addItem(const shared_ptr<StoredItem>& item); //add item function

    shared_ptr<StoredItem> findById(const string& id) const; //find item

    void removeItem(const string& id); //remove item

    void listItemsByDescription() const; //list all items
};