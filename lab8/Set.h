#ifndef SET
#define SET

#include<iostream>
using namespace std;

const int CAPACITY = 20;  // max number of items

typedef int ItemType;     // type of item to be stored

class Set{
// defines a set class that can hold 0 to CAPACITY items
// Items are of type ItemType and are unique (no duplicates)
// Items must be comparable using relational operators

    public:
        Set();
        // creates a Set object with 0 items in it

        bool empty () const;
        // returns true if Set object holds 0 items
        
        int getSize ()const;
        // returns number of items in Set
        
        bool add (const ItemType & item);
        // adds item to the set and returns true; if item is 
	    // already in the set or CAPACITY has been reached,
	    // item is not added and false is returned
               
        bool find (const ItemType & item);
        // returns true if item is in the set
        // returns false if item is not in the set
        
        bool remove (const ItemType & item);
        // removes item from the set and returns true if item is
	    // in the set; otherwise returns false
        
        void display (ostream & out) const;
        // sends items in the Set to the ostream provided
        // precondition: operator<< is defined for ItemType
                    
 	private:
 		 ItemType set[CAPACITY]; 
 		 int size;
 		 
 		 bool binSearch(int lo, int high, const ItemType & item);
 		 // recursive helper function: returns true if item is
 		 // found, false if item is not found
}; 
#endif   
        
