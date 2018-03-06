#ifndef PQueue_h
#define PQueue_h
#include "Job.h"

#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

 typedef Job* ItemType;

class PQueue{
    
   
    
public:
    
    PQueue();
    // default constructor of the class
    int size() const;
    // input is none
    // output is the amount of item inside the priority queue
    // side effect is none.
    bool empty();
    // input is none
    // output is boolean
    // side effect is none.
    void enqueue(ItemType & item);
    // input is itemtype
    // output is none
    // side effects are the size of array is changing, and class variable size increasing
    void dequeue();
    // input is none
    // output is none
    // side effects are the size of array is changing, and class variable size decreasing
    ItemType& front();
    // input is none
    // output is address of item which is holding inside the queue.
    // side effect is none.
    void addHeapOrder(int index);
    // input is vector of ItemType
    // output is none
    // side effect is that it will change item order in the vector.
    void deleteHeapOrder(int index);
    // input is type of int of index of the element
    // output is none
    // side effect is that the place of element will change inside this helper method. 
    
private:
    
    
    int sizeQ;
    
    vector<ItemType> jobs;
    
    
};



#endif /* PQueue_h */

