#include "Set.h"
 
 Set::Set(){
 	size = 0;
 }
 	
 bool Set::empty () const{
 	return size == 0;
 }
 
 int Set::getSize () const{
 	return size;
 }

bool Set::add (const ItemType & item){
	if(size == CAPACITY){
		return false;
	}
	int i = 0;
	bool added = false;
	while(i < size and item > set[i]){
		i++;
	}
	if(i == size){
		set[size] = item;
		added = true;
	}
	else
		if(item < set[i]) {
			for(int j = size; j > i; j--){
				set[j] = set[j-1];
			}
		set[i] = item;
		added = true;
	} 
 	if(added){
 		size++;
 	}
 	return added;
 }
 
bool Set::find (const ItemType & item){
	
	binSearch(0, size-1, item);
 }
 
bool Set::remove (const ItemType & item){
	int i = 0;
	bool found = false;
	while(i < size and ! found) {
		if (set[i] == item){
			found = true;
			for(i; i < size; i++) {
				set[i] = set[i+1];
			}
			size--;
		}
		i++;
	}	
	return found;
 }

 bool Set::binSearch(int lo, int high, const ItemType & item){

	

	if(lo > high){
		return false;
	}
	int medium = (lo + high)/2;
	
	if( item == set[medium]){
		return true;
	}
	if(item > set[medium]){
		return binSearch(++medium, high, item);
	}
	return binSearch(lo, --medium, item);
	
	
	


}
	
 void Set::display (ostream & out) const{
 	for(int i = 0; i < size; i++){
 		out << set[i] << endl;
 	}
 }
 
