#include "StorageManager.h"
#include "DuplicateItemException.h"
#include "ItemNotFoundException.h"
#include "StoredItem.h"
#include <iostream>

using namespace std;
//add item function
void StorageManager::addItem(const shared_ptr<StoredItem>& item) {
    string id = item->getId();

    if (itemById.find(id) != itemById.end()) {
        throw DuplicateItemException("Item with ID " + id + " already exists!");
    }

    itemById[id] = item;
    itemByDescription[item->getDescription()] = item;
}
//find item using the Id
shared_ptr<StoredItem> StorageManager::findById(const string& id) const {
    auto it = itemById.find(id);
    if (it != itemById.end()) {
        return it->second;
    }
    else {
        throw ItemNotFoundException("Item with ID " + id + " not found!");
    }
}
//remove item 
void StorageManager::removeItem(const string& id) {
    auto it = itemById.find(id);
    if (it == itemById.end()) {
        throw ItemNotFoundException("Cannot remove: Item with ID " + id + " not found!");
    }

    // Remove from itemByDescription using description
    string description = it->second->getDescription();
    itemByDescription.erase(description);

    // Remove from itemById
    itemById.erase(it);
}

//list items 
void StorageManager::listItemsByDescription() const {
    for (const auto& pair : itemByDescription) {
        auto item = pair.second;
        cout << "- " << item->getDescription() << ": " << item->getLocation() << endl;
    }
}
