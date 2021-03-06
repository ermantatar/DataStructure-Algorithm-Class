#include <cstdlib>
#include "SimpleListL.h"
#include <iostream>
#include <string>

using namespace std;

void append(const ItemType & item);
int listSize();
bool empty();
void display(ostream & out);



SimpleList::SimpleList(){ //this is constructor simply initialize class variables.
    head = NULL;
    last = NULL;
    size = 0;
}
bool SimpleList::empty() const{
    
    if(head == NULL){
        return true;
    }

    return false;
}

int SimpleList::listSize() const{
    
    return size;
}


void SimpleList::append(const ItemType & item){ // append function will add new member to list.

    Node *current = NULL;
    
    Node *n = new Node;
    
    n->next = NULL;
    n->data = item;
    
    if(head != NULL){
    
        current = head;
        
        while(current -> next != NULL){
            current = current->next;
        }
        current -> next = n;
        last = n;
        
    }else{
	head = n;
    }
    last = n;
    size++;
}

void SimpleList::display(ostream & out) const{
    Node * current = head;
    
    while(current != NULL) {
        cout<< current->data <<endl;
        current = current->next;
    }

}

