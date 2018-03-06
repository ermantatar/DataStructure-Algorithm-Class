// SimpleListD.cpp

#include <cassert>
#include "SimpleListD.h"
 
 SimpleList::SimpleList(){
 	cap = 10;
 	list = new ItemType[cap];
 	size = 0;
 }
 
 SimpleList::SimpleList(int capacity){
 	cap = capacity;
 	list = new ItemType[cap];
 	size = 0;
 }
 SimpleList::SimpleList(const SimpleList & listObject){
	cap = listObject.cap;
	size = listObject.size;
	
	list = new ItemType[cap];

	
	for(int i = 0; i< cap; i++){

		list[i] = listObject.list[i];
			
	}
}
 SimpleList::~SimpleList(){
	delete []list;

	}	
 bool SimpleList::empty () const{
 	return size == 0;
 }
 
 int SimpleList::listSize () const{
 	return size;
 }

 void SimpleList::insert (const ItemType & item, int position){
 	assert (position >= 0 && position <= size);
 	for(int i = size; i > position; i--){
 		list[i] = list[i-1];
 	}
 	list[position] = item;
 	size++;
 }
 
 ItemType SimpleList::retrieve (int position){
 	assert (position >= 0 && position < size);
 	return list[position];
 }
 
 void SimpleList::remove (int position){
 	assert (position >= 0 && position < size);
 	for(int i = position + 1; i < size; i++){
 		list[i - 1] = list[i];
 	}
 	size--;
 }
	
 void SimpleList::display (ostream & out) const{
 	for(int i = 0; i < size; i++){
 		out << list[i] << endl;
 	}
 }

SimpleList & SimpleList::operator=(SimpleList & listObject){
	
	delete[] list;

	cap = listObject.cap;
	size = listObject.size;
	
	list = new ItemType[cap];

	
	for(int i = 0; i< cap; i++){

		list[i] = listObject.list[i];
			
	}

	return *this;
	
}
 
