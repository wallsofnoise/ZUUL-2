#include <vector> // for vectors
#include <map> // for maps
#include "room.h" // allow access to room header file
#include "item.h" // allow access to item class

using namespace std;

Room::Room(char* newDescription, vector<Item*>* newItems, int newID) { // constructor
  description = newDescription;
  items = newItems;
  ID = newID;
}

char* Room::getDescription() { // get room description
  return description;
}

vector<Item*>* Room::getItems() { // get items in room
  return items;
}

int Room::getID() { // get room's ID number
  return ID;
}

void Room::setExits(map<char*,Room*>* newExits) { // set room exits
  exits = newExits;
}

map<char*,Room*>* Room::getExits() { // get room exits
  return exits;
}
