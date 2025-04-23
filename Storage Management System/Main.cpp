#include <iostream>                
#include "StorageManager.h"         
#include "StoredItem.h"             
#include "DuplicateItemException.h" 
#include "ItemNotFoundException.h"  


using namespace std;

int main() {
	StorageManager manager; //instance of storageManager
	
	//Adding first Item
	cout << "Adding item: ITEM001 - LED Light" << endl;
	shared_ptr<StoredItem> item1 = make_shared<StoredItem>("ITEM001", "LED Light", "Aisle 3, Shelf 1");
	manager.addItem(item1);

	//Adding Second Item
	cout << "Adding item: ITEM002 - Fand Motor" << endl;
	shared_ptr<StoredItem> item2 = make_shared<StoredItem>("ITEM002", "Fan Motor", "Aisle 2, Shelf 5");
	manager.addItem(item2);

	//Adding first Item again
	cout << "Attempting to add ITEM001 again..." << endl << endl;
	try {
		shared_ptr<StoredItem> otherItem1 = make_shared<StoredItem>("ITEM001", "LED Light", "Aisle 3, Shelf 1");
		manager.addItem(otherItem1);  // This will throw due to duplicate ID
	}
	catch (const DuplicateItemException& e) {
		cerr << "Error: " << e.what() << endl;  // Catches DuplicateItemException here
	}

	//Retreving Item by Id
	cout << "\nRetreving ITEM002..." << endl;
	cout << "Found " << manager.findById("ITEM002")->getDescription() << "at " << manager.findById("ITEM002")->getLocation() << endl <<endl;

	//Removing Item 3
	cout << "Removing ITEM003..." << endl;
	try {
		manager.removeItem("ITEM003"); // Attempt to remove a non-existent item
	}
	catch (const ItemNotFoundException& e) {
		cerr << "Error: " << e.what() << endl << endl;
	}


	//List all items in order
	cout << "Items in Description Order:" << endl;
	manager.listItemsByDescription();

	
	return 0;
}

