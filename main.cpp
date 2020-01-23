#include <iostream> // for cout and cin
#include <string.h> // for strcmp() and strcpy()
#include <vector> // for vectors
#include <map> // for maps
#include "room.h" // allow access to room class
#include "item.h" // allow access to item class

using namespace std;

// name: rose hall
// date: 01.23.20
// project: ZUUL. an adventure game featuring 15 rooms, 5 items, and no cohesive narrative whatsoever.

// function prototypes
void MOVE(Room* &currentRoom);
void TAKE(Room* currentRoom, vector<Item*>* &inv);
void DROP(Room* currentRoom, vector<Item*>* &inv);
void QUIT(bool &gameRunning);

int main() { // main method

  // bool for game loop
  bool gameRunning = true;

  // char arrays to store function names for strcmp input tests
  char moveF[] = "MOVE";
  char takeF[] = "TAKE";
  char dropF[] = "DROP";
  char quitF[] = "QUIT";

  // char array to store which function has been called
  char* calledFunction = new char[4];

  // char arrays to store directions
  char* north = new char[6];
  strcpy(north,"NORTH\0");
  char* south = new char[6];
  strcpy(south,"SOUTH\0");
  char* west = new char[5];
  strcpy(west,"WEST\0");
  char* east = new char[5];
  strcpy(east,"EAST\0");

  // create player inventory
  vector<Item*>* inv = new vector<Item*>;

  // create rooms

  // room 1
  char* desc1 = new char[500]; // create description array
  strcpy(desc1,"You are in the Trostland landing zone. You can see a church tower and the ruins of buildings."); // copy description to array
  vector<Item*>* roominv1 = new vector<Item*>; // create vector inv for room
  int rID1 = 1; // create room ID number
  Room* r1 = new Room(desc1,roominv1,rID1);

  // room 2
  char* desc2 = new char[500]; // create description array
  strcpy(desc2,"You are in the Trostland church tower. You can see steps leading up to the tower's top and a door into a system of tunnels beneath the church."); // copy description to array
  vector<Item*>* roominv2 = new vector<Item*>; // create vector inv for room
  int rID2 = 2; // create room ID number
  Room* r2 = new Room(desc2,roominv2,rID2);

  // room 3
  char* desc3 = new char[500]; // create description array
  strcpy(desc3,"You enter the Atrium lost sector. After dealing with a few Fallen dregs, the room becomes empty again."); // copy description to array
  vector<Item*>* roominv3 = new vector<Item*>; // create vector inv for room
  int rID3 = 3; // create room ID number
  Room* r3 = new Room(desc3,roominv3,rID3);

  // room 4
  char* desc4 = new char[500]; // create description array
  strcpy(desc4,"Devrim Kay reets you in his tower. 'Hello, guardian! Got those supplies for me yet?'"); // copy description to array
  vector<Item*>* roominv4 = new vector<Item*>; // create vector inv for room
  int rID4 = 4; // create room ID number
  Room* r4 = new Room(desc4,roominv4,rID4);

  // room 5
  char* desc5 = new char[500]; // create description array
  strcpy(desc5,"You explore the ruins, coming to a courtyard near the tower. A garage door stands half open, just enough for you to squeeze under. Another door opens into an old mining area."); // copy description to array
  vector<Item*>* roominv5 = new vector<Item*>; // create vector inv for room
  int rID5 = 5; // create room ID number
  Room* r5 = new Room(desc5,roominv5,rID5);

  // room 6
  char* desc6 = new char[500]; // create description array
  strcpy(desc6,"The mines are difficult to traverse, but you fight off any Fallen unfortunate enough to cross your path."); // copy description to array
  vector<Item*>* roominv6 = new vector<Item*>; // create vector inv for room
  int rID6 = 6; // create room ID number
  Room* r6 = new Room(desc6,roominv6,rID6);

  // room 7
  char* desc7 = new char[500]; // create description array
  strcpy(desc7,"You squeeze under the garage door and enter the Terminus East lost sector. Fallen come after you in swarms, but they're nothing to a Guardian of your prowess."); // copy description to array
  vector<Item*>* roominv7 = new vector<Item*>; // create vector inv for room
  int rID7 = 7; // create room ID number
  Room* r7 = new Room(desc7,roominv7,rID7);

  // room 8
  char* desc8 = new char[500]; // create description array
  strcpy(desc8,"You explore the ruins and come across what looks like ruined shops. You can enter, or move past them, deeper into the city."); // copy description to array
  vector<Item*>* roominv8 = new vector<Item*>; // create vector inv for room
  int rID8 = 8; // create room ID number
  Room* r8 = new Room(desc8,roominv8,rID8);

  // room 9
  char* desc9 = new char[500]; // create description array
  strcpy(desc9,"You enter the ruined shops. A door leads deeper into them, down a set of stairs."); // copy description to array
  vector<Item*>* roominv9 = new vector<Item*>; // create vector inv for room
  int rID9 = 9; // create room ID number
  Room* r9 = new Room(desc9,roominv9,rID9);

  // room 10
  char* desc10 = new char[500]; // create description array
  strcpy(desc10,"You descend into the Widow's Walk lost sector. After dispatching a nightmarish Fallen Captain who seems to keep showing up, the sector clears out again."); // copy description to array
  vector<Item*>* roominv10 = new vector<Item*>; // create vector inv for room
  int rID10 = 10; // create room ID number
  Room* r10 = new Room(desc10,roominv10,rID10);

  // room 11
  char* desc11 = new char[500]; // create description array
  strcpy(desc11,"You stroll deeper into the city, down a winding road through tall, ruined structures."); // copy description to array
  vector<Item*>* roominv11 = new vector<Item*>; // create vector inv for room
  int rID11 = 11; // create room ID number
  Room* r11 = new Room(desc11,roominv11,rID11);

  // room 12
  char* desc12 = new char[500]; // create description array
  strcpy(desc12,"You arrive in a ruined town square. Another crumbling church stands near it."); // copy description to array
  vector<Item*>* roominv12 = new vector<Item*>; // create vector inv for room
  int rID12 = 12; // create room ID number
  Room* r12 = new Room(desc12,roominv12,rID12);

  // room 13
  char* desc13 = new char[500]; // create description array
  strcpy(desc13,"A few Fallen try to jump you, but you easily fend them off and explore the ruined church."); // copy description to array
  vector<Item*>* roominv13 = new vector<Item*>; // create vector inv for room
  int rID13 = 13; // create room ID number
  Room* r13 = new Room(desc13,roominv13,rID13);

  // room 14
  char* desc14 = new char[500]; // create description array
  strcpy(desc14,"Stepping back from the landing zone a bit leads you to a sharp cliff. A ruined buidling off to the side seems to have partially fallen into the gluch."); // copy description to array
  vector<Item*>* roominv14 = new vector<Item*>; // create vector inv for room
  int rID14 = 14; // create room ID number
  Room* r14 = new Room(desc14,roominv14,rID14);

  // room 15
  char* desc15 = new char[500]; // create description array
  strcpy(desc15,"You clamber about on the collapsed building, but there doesn't seem to be anything of interest."); // copy description to array
  vector<Item*>* roominv15 = new vector<Item*>; // create vector inv for room
  int rID15 = 15; // create room ID number
  Room* r15 = new Room(desc15,roominv15,rID15);

  // create and add items to rooms

  // item 1
  char* name1 = new char[20]; // create name array
  strcpy(name1,"Atrium Cache"); // copy name to array
  char* idesc1 = new char[100]; // create description array
  strcpy(idesc1,"A supply cache full of glimmer."); // copy description to array
  int ID1 = 1; // set ID
  Item* i1 = new Item(name1,idesc1,ID1); // create a new item using all proper components
  r3->getItems()->push_back(i1); // push item to proper room's inv

  // item 2
  char* name2 = new char[20]; // create name array
  strcpy(name2,"Signal Booster"); // copy name to array
  char* idesc2 = new char[100]; // create description array
  strcpy(idesc2,"A signal booster for a communications system."); // copy description to array
  int ID2 = 2; // set ID
  Item* i2 = new Item(name2,idesc2,ID2); // create a new item using all proper components
  r6->getItems()->push_back(i2); // push item to proper room's inv

  // item 3
  char* name3 = new char[20]; // create name array
  strcpy(name3,"Terminus Cache"); // copy name to array
  char* idesc3 = new char[100]; // create description array
  strcpy(idesc3,"A supply cache full of weapons."); // copy description to array
  int ID3 = 3; // set ID
  Item* i3 = new Item(name3,idesc3,ID3); // create a new item using all proper components
  r7->getItems()->push_back(i3); // push item to proper room's inv

  // item 4
  char* name4 = new char[20]; // create name array
  strcpy(name4,"Widow's Cache"); // copy name to array
  char* idesc4 = new char[100]; // create description array
  strcpy(idesc4,"A supply cache full of armor."); // copy description to array
  int ID4 = 4; // set ID
  Item* i4 = new Item(name4,idesc4,ID4); // create a new item using all proper components
  r10->getItems()->push_back(i4); // push item to proper room's inv

  // item 5
  char* name5 = new char[20]; // create name array
  strcpy(name5,"Exotic Engram"); // copy name to array
  char* idesc5 = new char[100]; // create description array
  strcpy(idesc5,"An engram of exotic rarity."); // copy description to array
  int ID5 = 5; // set ID
  Item* i5 = new Item(name5,idesc5,ID5); // create a new item using all proper components
  r13->getItems()->push_back(i5); // push item to proper room's inv

  // create and assign maps

  // room 1 map
  map<char*,Room*>* map1 = new map<char*,Room*>(); // create map
  map1->insert(pair<char*,Room*>(north,r2)); // assign north exit
  map1->insert(pair<char*,Room*>(south,r14)); // assign south exit
  map1->insert(pair<char*,Room*>(west,r8)); // assign west exit
  map1->insert(pair<char*,Room*>(east,r5)); // assign east exit
  r1->setExits(map1); // assign map to room

  // room 2 map
  map<char*,Room*>* map2 = new map<char*,Room*>(); // create map
  map2->insert(pair<char*,Room*>(north,r3)); // assign north exit
  map2->insert(pair<char*,Room*>(south,r1)); // assign south exit
  map2->insert(pair<char*,Room*>(west,NULL)); // assign west exit
  map2->insert(pair<char*,Room*>(east,r4)); // assign east exit
  r2->setExits(map2); // assign map to room

  // room 3 map
  map<char*,Room*>* map3 = new map<char*,Room*>(); // create map
  map3->insert(pair<char*,Room*>(north,NULL)); // assign north exit
  map3->insert(pair<char*,Room*>(south,r2)); // assign south exit
  map3->insert(pair<char*,Room*>(west,NULL)); // assign west exit
  map3->insert(pair<char*,Room*>(east,NULL)); // assign east exit
  r3->setExits(map3); // assign map to room

  // room 4 map
  map<char*,Room*>* map4 = new map<char*,Room*>(); // create map
  map4->insert(pair<char*,Room*>(north,NULL)); // assign north exit
  map4->insert(pair<char*,Room*>(south,NULL)); // assign south exit
  map4->insert(pair<char*,Room*>(west,r2)); // assign west exit
  map4->insert(pair<char*,Room*>(east,NULL)); // assign east exit
  r4->setExits(map4); // assign map to room

  // room 5 map
  map<char*,Room*>* map5 = new map<char*,Room*>(); // create map
  map5->insert(pair<char*,Room*>(north,r6)); // assign north exit
  map5->insert(pair<char*,Room*>(south,NULL)); // assign south exit
  map5->insert(pair<char*,Room*>(west,r1)); // assign west exit
  map5->insert(pair<char*,Room*>(east,r7)); // assign east exit
  r5->setExits(map5); // assign map to room

  // room 6 map
  map<char*,Room*>* map6 = new map<char*,Room*>(); // create map
  map6->insert(pair<char*,Room*>(north,NULL)); // assign north exit
  map6->insert(pair<char*,Room*>(south,r5)); // assign south exit
  map6->insert(pair<char*,Room*>(west,NULL)); // assign west exit
  map6->insert(pair<char*,Room*>(east,NULL)); // assign east exit
  r6->setExits(map6); // assign map to room

  // room 7 map
  map<char*,Room*>* map7 = new map<char*,Room*>(); // create map
  map7->insert(pair<char*,Room*>(north,NULL)); // assign north exit
  map7->insert(pair<char*,Room*>(south,NULL)); // assign south exit
  map7->insert(pair<char*,Room*>(west,r5)); // assign west exit
  map7->insert(pair<char*,Room*>(east,NULL)); // assign east exit
  r7->setExits(map7); // assign map to room

  // room 8 map
  map<char*,Room*>* map8 = new map<char*,Room*>(); // create map
  map8->insert(pair<char*,Room*>(north,r9)); // assign north exit
  map8->insert(pair<char*,Room*>(south,NULL)); // assign south exit
  map8->insert(pair<char*,Room*>(west,r11)); // assign west exit
  map8->insert(pair<char*,Room*>(east,r1)); // assign east exit
  r8->setExits(map8); // assign map to room

  // room 9 map
  map<char*,Room*>* map9 = new map<char*,Room*>(); // create map
  map9->insert(pair<char*,Room*>(north,r10)); // assign north exit
  map9->insert(pair<char*,Room*>(south,r8)); // assign south exit
  map9->insert(pair<char*,Room*>(west,NULL)); // assign west exit
  map9->insert(pair<char*,Room*>(east,NULL)); // assign east exit
  r9->setExits(map9); // assign map to room

  // room 10 map
  map<char*,Room*>* map10 = new map<char*,Room*>(); // create map
  map10->insert(pair<char*,Room*>(north,NULL)); // assign north exit
  map10->insert(pair<char*,Room*>(south,r9)); // assign south exit
  map10->insert(pair<char*,Room*>(west,NULL)); // assign west exit
  map10->insert(pair<char*,Room*>(east,NULL)); // assign east exit
  r10->setExits(map10); // assign map to room

  // room 11 map
  map<char*,Room*>* map11 = new map<char*,Room*>(); // create map
  map11->insert(pair<char*,Room*>(north,NULL)); // assign north exit
  map11->insert(pair<char*,Room*>(south,r12)); // assign south exit
  map11->insert(pair<char*,Room*>(west,NULL)); // assign west exit
  map11->insert(pair<char*,Room*>(east,r8)); // assign east exit
  r11->setExits(map11); // assign map to room

  // room 12 map
  map<char*,Room*>* map12 = new map<char*,Room*>(); // create map
  map12->insert(pair<char*,Room*>(north,r11)); // assign north exit
  map12->insert(pair<char*,Room*>(south,r13)); // assign south exit
  map12->insert(pair<char*,Room*>(west,NULL)); // assign west exit
  map12->insert(pair<char*,Room*>(east,NULL)); // assign east exit
  r12->setExits(map12); // assign map to room

  // room 13 map
  map<char*,Room*>* map13 = new map<char*,Room*>(); // create map
  map13->insert(pair<char*,Room*>(north,r12)); // assign north exit
  map13->insert(pair<char*,Room*>(south,NULL)); // assign south exit
  map13->insert(pair<char*,Room*>(west,NULL)); // assign west exit
  map13->insert(pair<char*,Room*>(east,NULL)); // assign east exit
  r13->setExits(map13); // assign map to room

  // room 14 map
  map<char*,Room*>* map14 = new map<char*,Room*>(); // create map
  map14->insert(pair<char*,Room*>(north,r1)); // assign north exit
  map14->insert(pair<char*,Room*>(south,NULL)); // assign south exit
  map14->insert(pair<char*,Room*>(west,r15)); // assign west exit
  map14->insert(pair<char*,Room*>(east,NULL)); // assign east exit
  r14->setExits(map14); // assign map to room

  // room 15 map
  map<char*,Room*>* map15 = new map<char*,Room*>(); // create map
  map15->insert(pair<char*,Room*>(north,NULL)); // assign north exit
  map15->insert(pair<char*,Room*>(south,NULL)); // assign south exit
  map15->insert(pair<char*,Room*>(west,NULL)); // assign west exit
  map15->insert(pair<char*,Room*>(east,r14)); // assign east exit
  r15->setExits(map15); // assign map to room

  // create variable to track current room and set default room
  Room* currentRoom = r1;

  // give information about program and how to operate it
  cout << "this is a text-based adventure game, operated by commands!\nyou type 'MOVE' into the console to move in a direction between two rooms.\nyou can type 'TAKE' into the console to pick up objects in a room if any are available.\nyou can type 'DROP' into the console to drop an item into your current room.\nyou can type 'QUIT' into the console to quit at any time." << endl;

  while (gameRunning == true) { // game loop
    // provide information on current room
    cout << currentRoom->getDescription() << endl;
    if (currentRoom->getItems()->size() > 0) { // if there are items in the room
      cout << "current items in room:" << endl;
      vector<Item*>::iterator it; // create iterator
      for (it = (currentRoom->getItems())->begin(); it != (currentRoom->getItems())->end(); it++) { // iterate through room's item array and print items
	cout << (*it)->getName() << ": " << (*it)->getDescription() << " (" << (*it)->getID() << ")" << endl;
      }
    }

    // check win condition

    if (currentRoom->getID() == 4 && inv->size() == 5) { // if in r4 and 
      cout << "Devrim hails you. 'Ah, Guardian! You have all the supplies. You're ready to adventure out into the rest of the EDZ. Good luck you there.'" << endl;
      cout << "You've won the game! Thanks for playing." << endl;
      break;
    }
    
    // prompt for input
    cout << "what would you like to do?" << endl;
    // take input to determine which function will be called
    cin >> calledFunction;
    cin.get();

    if (strcmp(calledFunction,moveF) == 0) { // if called, perform move function
      MOVE(currentRoom);
    }

    else if (strcmp(calledFunction,takeF) == 0) { // if called, perform take function
      TAKE(currentRoom,inv);
    }

    else if (strcmp(calledFunction,dropF) == 0) { // if called, perform drop function
      DROP(currentRoom,inv);
    }

    else if (strcmp(calledFunction,quitF) == 0) { // if called, perform quit function
      QUIT(gameRunning);
    }

    else { // if input is invalid, inform user
      cout << "your command was not recognized! please try again." << endl;
    }
  }
}

void MOVE(Room* &currentRoom) { // move function
  // create variable to store directional input
  char* directionMoved = new char[5];
  // prompt for directional input
  cout << "which direction would you like to move? (NORTH, SOUTH, EAST, WEST)" << endl;
  // take directional input
  cin >> directionMoved;
  cin.get();
  // create iterator
  map<char*,Room*>::iterator it;
  for (it = (currentRoom->getExits())->begin(); it != (currentRoom->getExits())->end(); it++) { // move through list of room exits
    if(strcmp(directionMoved,(*it).first) == 0 && (*it).second != NULL) { // if direction matches an exit and the exit doesn't lead to a null room
      // move to that room
      currentRoom = (*it).second;
      // exit function
      return;
    }
    else { // if direction isn't found, continue
      continue;
    }
  }
  // if the direction inputted didn't match to a valid exit, inform the player.
  cout << "you can't move that direction! try again." << endl;
}

void TAKE(Room* currentRoom, vector<Item*>* &inv) { // take function
  // create int for input
  int takeID;
  if (currentRoom->getItems()->size() == 0) { // if room is empty, inform player
    cout << "there's nothing to take here." << endl;
  }
  else { // if room contains any amount of items
    // prompt user for input
    cout << "which item would you like to take? use the ID number in parentheses to select." << endl;
    // take user input
    cin >> takeID;
    // create an iterator
    vector<Item*>::iterator it;
    for (it = (currentRoom->getItems())->begin(); it != (currentRoom->getItems())->end(); it++) { // iterate through items in room
      if (takeID == (*it)->getID()) { // if item IDs match
	inv->push_back(*it); // add item to player inventory
	currentRoom->getItems()->erase(it); // erase item from room inventory
	return; // exit function
      }
      else { // if item IDs don't match, continue running
	continue;
      }
    }
    // if no item matches, inform player
    cout << "no item exists in this room with that ID!" << endl;
  }
}

void DROP(Room* currentRoom, vector<Item*>* &inv) { // drop function
  // create int for input
  int dropID;
  if (inv->size() == 0) { // if their inventory is empty, inform player
    cout << "you're not carrying anything." << endl;
  }
  else { // if inventory contains any amount of items
    // prompt user for input
    cout << "which item would you like to take? use the ID number in parentheses to select." << endl;
    // create iterator
    vector<Item*>::iterator it;
    for (it = inv->begin(); it != inv->end(); it++) { // iterate player's inventory item array and print items
	cout << (*it)->getName() << ": " << (*it)->getDescription() << " (" << (*it)->getID() << ")" << endl;
    }
    // take user input
    cin >> dropID;
    for (it = inv->begin(); it != inv->end(); it++) { // iterate through player's inventory again
      if (dropID == (*it)->getID()) { // if item IDs match
	currentRoom->getItems()->push_back(*it); // add item to room inventory
	inv->erase(it); // erase item from player inventory
	return; // exit function
      }
      else { // if IDs don't match, continue running
	continue;
      }
    }
    // if no item matches, inform player
    cout << "that item isn't in your inventory!" << endl;
  }
}

void QUIT(bool &gameRunning) {
  // inform user that game is being quit
  cout << "shutting down..." << endl;
  // break game loop
  gameRunning = false;
}
