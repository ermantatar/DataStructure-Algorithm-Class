// SimpleListD.h
#ifndef SIMPLELIST
#define SIMPLELIST

#include<iostream>
using namespace std;

typedef int ItemType;     // type of item to be stored

class SimpleList{
// defines a container class that can hold 0 to
// capacity items, each of type ItemType
// class invariant:  items are stored in positions 0 to n-1 where
// n is the the number of items stored in the list and n <= capacity

    public:
        SimpleList();
        // creates a SimpleList object with 0 items in it
        // and a capacity to 10

	~SimpleList();
	// deconstructor will delete existing memory space.
       
        SimpleList(int capacity);
        // creates a SimpleList object with 0 items in it
		// and the capacity specified
	SimpleList(const SimpleList & listObject);
	//copy constructor.
		
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
	
	SimpleList & operator=(SimpleList & list);
	
        
        void display (ostream & out) const;
        // sends items in SimpleList to the ostream provided
        // precondition: operator<< is defined for ItemType
                    
 	private:
 		 ItemType* list; 
 		 int size;
 		 int cap;
}; 
#endif   
        
