#ifndef QUEUE
#define QUEUE
#include<iostream>

using namespace std;

typedef string ElementType;  // type of item to be stored

class Queue{
    // define a container class that can hold an unspecified
    // number of items, each of type ItemType
    // where n is the the number of items stored in the list
    
public:
    Queue();
    // create a Queue object with 0 items in it
    
    ~Queue();
    // will return heap memoy space.
    
    bool Qempty () const;
    // return true if Queue object holds 0 items
    
    int QSize ()const;
    // return number of items in Queue
    
    void enqueue (const ElementType & item);
    // add item at the end of Queue
    
    ElementType dequeue ();
    // return item at top of the Queue
    
    ElementType front () const;
    // return an item at specified position
    
    void Qdisplay (ostream & out) const;
    // sends items in Queue to the ostream provided
    // precondition: operator<< is defined for ItemType
    
    
private:
    // a Node holds an item and a pointer to the next Node. Since it is
    // only visible to the Queue class its data members are public
    class Node{
    public:
        ElementType data;
        Node * next;
    };
    Node * top;
    Node * bottom;
    int Qsize;
};
#endif


