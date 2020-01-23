// header guard
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector> // for vectors
#include <map> // for maps
#include "item.h" // allow access to item class

using namespace std;

class Room { // room class
 public:
  // constructor
  Room(char*,vector<Item*>*,int);
  // function prototypes
  char* getDescription(); // will return room's description
  vector<Item*>* getItems(); // will return items in room
  int getID();
  void setExits(map<char*,Room*>*); // will set room's exits
  map<char*,Room*>* getExits(); // will return room's exits
 private:
  // variables
  char* description;
  vector<Item*>* items;
  int ID;
  map<char*,Room*>* exits;
};

#endif
// header guard end
