#include<iostream>
#include<utility>
#include <string>
using namespace std;

typedef string KeyType;           
typedef string* ValueType;   
typedef pair<KeyType, ValueType> ItemType;  

void fillArray(ItemType list[], int size);
//input: an array and its size
//output: the array has size items (key-value pairs) in it
//side effects: none

ValueType getValue(KeyType key, ItemType list[], int size);
//input: an array, its size and a key
//output: return the value associated with the key given or a null pointer
//side effects: none

void printItems(ItemType list[], int size);
//input: an array and its size
//output: none
//side effects: prints the items in the array

int main(){
	//declare an array that can hold 3 items (name - phone number pairs)
	ItemType list[3];
	ValueType value;
	ValueType unvaluable;
	
	
	//call fillArray

	fillArray(list, 3);
	
	//call printItems
	printItems(list, 3);
	
	//call getValue sending it a name
	value = getValue("Alex", list, 3);
	
	//if the name was found change the phone number
	if(value != NULL){
		*value = "987 768 55 64";

	}else{

		cout<< "Your name is not in computer contacts"<<endl; 
	}

	//if the name was not found print a message

	unvaluable = getValue("Erman", list, 3);
	if(unvaluable != NULL){

		*unvaluable = "456 345 43 34";
	}else{
		cout<< "Your name is not in computer contacts"<< endl; 
	}
	
	
	printItems(list, 3);
}

void fillArray(ItemType list[], int size){

	list[0] = make_pair("Alex",new string("789 156 55 84"));
	list[1] = make_pair("Micheal",new string("123 123  85"));
	list[2] = make_pair("David", new string("456 454 45 54"));


}

ValueType getValue(KeyType key, ItemType list[], int size){


	for(int i = 0; i < size; i++){
	
		if(key == list[i].first){
			return list[i].second;
	
		}
	}	
	return NULL;
}

void printItems(ItemType list[], int size){

	for(int i = 0; i< size; i++){
	
	cout << "Name is : " << list[i].first << endl;
	cout << "Phone Number is " << *list[i].second << endl;

	}



}

