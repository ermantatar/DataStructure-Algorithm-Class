#ifndef SET
#define SET

#include<iostream>

using namespace std;



typedef string ItemType;     // type of item to be stored

class Set{
    // defines a set class that can hold 0 to CAPACITY items
    // Items are of type ItemType and are unique (no duplicates)
    // Items must be comparable using relational operators
    
public:
    Set();
    // creates a Set object with 0 items in it
    
    ~Set();
    // return heap memory space
    
    Set(Set & listObject);
    // it is copy constructor for our application program.
    
    bool empty () const;
    // returns true if Set object holds 0 items
    
    int getSize ()const;
    // returns number of items in Set
    
    bool add (const ItemType & item);
    // adds item to the set and returns true; if item is
    // already in the set 
    // item is not added and false is returned
    
    bool find (const ItemType & item);
    // returns true if item is in the set
    // returns false if item is not in the set
    
    bool remove (const ItemType & item);
    // removes item from the set and returns true if item is
    // in the set; otherwise returns false
    
    void display (ostream & out);
    // sends items in the Set to the ostream provided
    // precondition: operator<< is defined for ItemType
    
    int height();
    // it will return height of the tree.
    
    
private:
    
 		class Node{
         
        public:
            Node *right;
            Node *left;
            ItemType data;
             
        };
    
    int size;
    Node *root;
 		 
    bool binSearch(Node* & rootTree, const ItemType & item);
 		 // recursive helper function: returns true if item is
 		 // found, false if item is not found.
             
    int findHeight(Node* & node);
        // it will find height of the tree with recursively
        // it will return the height of the tree.
    
    void deleteNode(Node* & node);
        // it will delete for deconstructor
    
    void copyNode(Node* &node);
        // it is helper method for copy constructor
    
    void displayNode(Node* & node, ostream & out);
        // it is helper method for my display method
    
    void addNode(const ItemType & item, Node * & node);
    
    Node* findMinimumNode(Node * & node);
        // function to find minumum in tree.
    
    bool deleteHelper(Node* & node, const ItemType & item);
        // it is helper method for remove function.
    
    
};


#endif


