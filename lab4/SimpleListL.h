#ifndef SIMPLELIST
#define SIMPLELIST
#include<iostream>
using namespace std;

typedef int ItemType;  // type of item to be stored

class SimpleList{
    // define a container class that can hold an unspecified
    // number of items, each of type ItemType
    // class invariant:  items are stored in positions 1 to n
    // where n is the the number of items stored in the list
    
public:
    SimpleList();
    // create a SimpleList object with 0 items in it
    
    bool empty () const;
    // return true if SimpleList object holds 0 items
    
    int listSize ()const;
    // return number of items in SimpleList
    
    void append (const ItemType & item);
    // insert item at the end of SimpleList
    
    void insert (const ItemType & item, int position);
    // insert item at the specified position
    // precondition: position > 0 and position <= number of items + 1
    
    ItemType retrieve (int position)const;
    // return item at specified position
    // precondition: position > 0 and position <= number of items
    
    void remove (int position);
    // remove item at specified position
    // precondition: position > 0 and position <= number of items
    
    void display (ostream & out) const;
    // sends items in SimpleList to the ostream provided
    // precondition: operator<< is defined for ItemType
    
private:
    // a Node holds an item and a pointer to the next Node. Since it is
    // only visible to the SimpleList class its data members are public
    class Node{
 			public:
        ItemType data;
        Node * next;
    };
    Node * head;
    Node * last;
    int size;
};
#endif

