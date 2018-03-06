#ifndef SIMPLELIST
#define SIMPLELIST
#include <iostream>
#include "player.h"

using namespace std;

const int CAPACITY = 20;  // max number of items

typedef TennisPlayer ItemType;     // type of item to be stored

class SimpleList{
    // defines a container class that can hold 0 to
    // CAPACITY items, each of type ItemType
    // class invariant:  items are stored in positions 0 to n-1 where
    // n is the the number of items stored in the list and n <= CAPACITY
    
public:
    SimpleList();
    // creates a SimpleList object with 0 items in it
    
    bool empty () const;
    // returns true if SimpleList object holds 0 items
    
    int listSize ()const;
    // returns number of items in SimpleList
    
    void insert (const ItemType & item, int position);
    // inserts item at specified position
    // precondition: position >=0 and <= number of items
    
    ItemType retrieve (int position);
    // return the item stored at specified position
    // precondition: position >=0 and < number of items
    
    void remove (int position);
    // remove the item stored at specified position
    // precondition: position >=0 and < number of items
    
    void display (ostream & out) const;
    // sends items in SimpleList to the ostream provided
    // precondition: operator<< is defined for ItemType
    
private:
 		 ItemType list[CAPACITY];
 		 int size;
};
#endif
