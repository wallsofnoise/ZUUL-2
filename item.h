// header guard
#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

class Item { // item class
public:
  // constructor
  Item(char*,char*,int);
  // destructor
  ~Item();
  // function prototypes
  char* getName(); // will return item's name
  char* getDescription(); // will return item's description
  int getID(); // will return item's ID
private:
  // variables
  char* name;
  char* description;
  int ID;
};

#endif
// header guard end
