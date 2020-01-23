#include "item.h" // allow access to item header file

using namespace std;

Item::Item(char* newName, char* newDescription, int newID) { // constructor
  name = newName;
  description = newDescription;
  ID = newID;
}

Item::~Item() { // desctructor
  delete name;
  delete description;
}

char* Item::getName() { // return item's name
  return name;
}

char* Item::getDescription() { // return item's description
  return description;
}

int Item::getID() { // return item's ID
  return ID;
}
