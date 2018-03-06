#include <cstdlib>
#include "Queue.h"
#include <iostream>
#include <string>
#include <cassert>



using namespace std;

Queue::Queue(){
    top = NULL;
    bottom = NULL;
    Qsize = 0;
}


Queue::~Queue(){
    
    Node *ptr;
    
    
    while(top != NULL){
        ptr = top;
        top = top->next;
        delete ptr;
        
    }
    ptr = top;
    delete ptr;
    top = NULL;
}

bool Queue::Qempty() const{
    
    if(top == NULL){
        return true;
    }
    
    return false;
}

int Queue::QSize() const{
    
    return Qsize;
}

void Queue::enqueue(const ElementType & item){ // add new member top of thelist.
    
    Node *n = new Node;
    
    n->next = NULL;
    n->data = item;
    
    if(top == NULL){
        
        top = n;
        bottom = n;
        n->next = NULL;
        
    }else{
        bottom->next = n;
       	bottom = n;
        
    }
    Qsize++;
    return;
}

ElementType Queue::dequeue(){
    
    
    assert(Qsize>0);
    ElementType returnData;
    Node * firstItem;
    
    firstItem = top;
    
    returnData = top->data;
    top = top->next;
    
    Qsize--;
    delete firstItem;
    return returnData;
    
}

ElementType Queue::front() const{
    
    return top->data;
}

void Queue::Qdisplay(ostream & out) const{
    Node * current = top;
    
    while(current != NULL) {
        cout<< current->data <<endl;
        current = current->next;
    }
    
}



