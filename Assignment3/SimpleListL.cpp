#include <cstdlib>
#include "SimpleListL.h"
#include <iostream>
#include <string>

using namespace std;


SimpleList::SimpleList(){   //this is constructor simply initialize class variables.
    head = NULL;
    last = NULL;
    size = 0;
    currentPosition = head;
    
}
SimpleList::SimpleList(const SimpleList & listToCopy){
    
    Node *current = NULL;
    Node *nextnode = NULL;
    
    if(listToCopy.head == NULL){
        head = NULL;
        last = NULL;
        size = 0;
        currentPosition = 0;
    }else{
        head = new Node;
        head->data = listToCopy.head->data;
        
        current = head;
        nextnode = listToCopy.head->next;
    
    
        while (nextnode) {
        
            current->next = new Node;
            current = current->next;
            current->data = nextnode->data;
            nextnode = nextnode->next;
        }
        last = current;
        size = listToCopy.size;
        currentPosition = head;
    }
    current->next = NULL;
        
    
}

SimpleList::~SimpleList(){

    Node *ptr;
    
    while(head != NULL){
        ptr = head;
        head = head->next;
        delete ptr;
    
    }
    ptr = head;
    delete ptr;
    head = NULL;
    last = NULL;
	
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
    
    if(head == NULL){
        
        head = n;
        last = n;
        size++;
        return;
        
    }else{
        
        
        current = head;
        
        while(current -> next != NULL){
            current = current->next;
        }
        current -> next = n;
        last = n;
        
    }
    size++;
    return;
}
void SimpleList::display(ostream & out) const{
    Node * current = head;
    
    while(current != NULL) {
        cout<< current->data <<endl;
        current = current->next;
    }
    
}
void SimpleList::remove(int position){
    
    Node *delPtr = NULL;
    Node *temp = head;
    Node *current = head;
    int counter = 1;
    if (position == 1){
	delPtr = head;
	head = head->next;
	delete delPtr;
	return;
	}
    while (position != counter) {
        temp = current;
        current = current->next;
        counter++;
    }
    delPtr = current;
    temp->next = current->next;
    //current = current->next;
    delete delPtr;
}
ItemType SimpleList::retrieve(int position) const{

    Node *current = head;
    int counter = 1;
    
    while (position != counter) {
        current = current->next;
        counter++;
    }
    
    return current->data;
}

void SimpleList::insert(const ItemType &item, int position){
    
    if(position <= 0 || position > size+1){
		return;

	}

    Node *newNode = new Node;
    newNode->data = item;
    newNode->next = NULL;
    
    Node *before = head;
    Node *after = head;
    int counter = 1;
    if (size == 0){
        
        head = newNode;
        last = newNode;
        size++;
        
    }else if (position == size+1) {
            last->next = newNode;
            size++;
            last = newNode;
        }
    else if(position == 1){
        newNode->next = head;
        size++;
        head = newNode;
    }else{
        
        while (position != counter) {
            before = after;
            after = after->next;
            counter++;
        }
        before->next = newNode;
        newNode->next = after;
        size++;
        
    }
}

void SimpleList::moveToStart(){
    currentPosition = head;
}
void SimpleList::next(){
    currentPosition = currentPosition->next;
}
ItemType SimpleList::getItem() const{
    return currentPosition->data;
}
bool SimpleList::pastTheEnd() const{
    if( currentPosition == last){
        return true;
    }
    else{
        return false;
    }
}

SimpleList& SimpleList::operator=(const SimpleList & listToCopy){

    
    Node *ptr;
    
    while(head->next != NULL){
        ptr = head;
        head = head->next;
        delete ptr;
        
    }
    ptr = head;
    delete ptr;
    head = NULL;
    last = NULL;
    
    Node *current = NULL;
    Node *nextnode = NULL;
    
    if(listToCopy.head == NULL){
        head = NULL;
        last = NULL;
        size = 0;
        currentPosition = 0;
    }else{
        head = new Node;
        head->data = listToCopy.head->data;
        
        current = head;
        nextnode = listToCopy.head->next;
        
        
        while (nextnode) {
            
            current->next = new Node;
            current = current->next;
            current->data = nextnode->data;
            nextnode = nextnode->next;
        }
        last = current;
        size = listToCopy.size;
        currentPosition = head;
    }
    current->next = NULL;

    
    return *this;

}

