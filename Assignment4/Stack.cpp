#include <cstdlib>
#include "Stack.h"
#include <iostream>
#include <string>
#include <cassert>



using namespace std;

Stack::Stack(){
    head = NULL;
    size = 0;
}


Stack::~Stack(){
    
    Node *ptr;
    
    while(head != NULL){
        ptr = head;
        head = head->next;
        delete ptr;
        
    }
    ptr = head;
    delete ptr;
    head = NULL;
}

bool Stack::empty() const{
    
    if(head == NULL){
        return true;
    }
    
    return false;
}

int Stack::stackSize() const{
    
    return size;
}

void Stack::push(const ItemType & item){ // add new member top of thelist.
    
    Node *current = NULL;
    
    Node *n = new Node;
    
    n->next = NULL;
    n->data = item;
    
    if(head == NULL){
        
        head = n;
        n->next = NULL;
        
    }else{
        n->next = head;
       	head = n;
        
    }
    size++;
    return;
}

ItemType Stack::pop(){
    
    assert(size>0);
    ItemType returnData;
    Node * lastItem;
    
    lastItem = head;
    returnData = lastItem->data;
    head = head->next;
    
    
    delete lastItem;
    return returnData;
}

ItemType Stack::top() const{
    
    return head->data;
}

void Stack::display(ostream & out) const{
    Node * current = head;
    
    while(current != NULL) {
        cout<< current->data <<endl;
        current = current->next;
    }
    
}

