#ifndef STACK
#define STACK
#include<iostream>

using namespace std;

typedef int ItemType;  // type of item to be stored

class Stack{
    // define a container class that can hold an unspecified
    // number of items, each of type ItemType
    // where n is the the number of items stored in the list
    
public:
    Stack();
    // create a Stack object with 0 items in it

    ~Stack();
    // will return heap memoy space.
    
    bool empty () const;
    // return true if Stack object holds 0 items
    
    int stackSize ()const;
    // return number of items in Stack
    
    void push (const ItemType & item);
    // add item at the end of Stack
    
    ItemType pop ();
    // return item at top of the stack
    
    ItemType top () const;
    // return an item at specified position
	
    void display (ostream & out) const;
    // sends items in Stack to the ostream provided
    // precondition: operator<< is defined for ItemType

    
private:
    // a Node holds an item and a pointer to the next Node. Since it is
    // only visible to the Stack class its data members are public
    class Node{
 	public:
        ItemType data;
        Node * next;
    };
    Node * head;
    int size;
};
#endif

