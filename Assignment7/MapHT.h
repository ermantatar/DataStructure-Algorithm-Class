

#ifndef MAPHT_h
#define MAPHT_h

#include<string>
#include<list>
#include<vector>
#include "BankAccount.h"

using namespace std;

typedef int KeyType;

typedef BankAccount * ValueType;
typedef pair<KeyType, ValueType> ItemType;
typedef int(* hashFunc)(KeyType key, int tsize);


class MapHT{

    public :
    
    MapHT(int tsize, hashFunc func);
    // input : size of hash table to be constructed,
    //         and the hash function to be used
    //output : none
    // side effects : chained hash table is created.
    
    double loadFactor() const;
    // input : none
    // output : load factor of the hash table
    // side effects are none.
    
    bool empty();
    // input is none, output is bool.
    // there is no side effects.
    
    int size();
    // input is none.
    // output is size of map.
    
    
    bool findItem(const KeyType & key);
    // input is key value of bank account.
    // output is true if there is an item with this key, false if there
    
    bool addItem(const KeyType & key, const ValueType & value);
    // input is pairs which is include key and value.
    // output is bool.
    // side effect is changing hashtable and size of hashtable.
    
   
    ValueType retrieveItem(KeyType key);
    // input is the key type string
    // output is pointer of bank account class.
    // side effect is none
    
    ValueType removeItem(KeyType & key);
    // input is the address of the key
    // output is pointer of bank account class.
    // side effect is deleting item inside the Bank object.
    
    void displayItems(ostream & out);
    // input is the out object address from ostream class
    // output is none.
    // side effect is displaying items on the screen
    
    void displayStats(ostream & out);
    // input is the out object address from ostream class
    // output is none.
    // side effect is displaying items on the screen
    
    unsigned long longestListLenght();
    // input is none.
    // output is lenght of the longest list inside the Map.
    // side effect is creating some object of stl class.
    
    double averageListLenght();
    // input is none.
    // output is average lenght inside the Map.
    // side effect is creating some object of stl class.
    
    private :
    
    // data members of my class.
    
    int tsize;
    // table size
    
    int sizeMap;
    // all items inside the hashtable
    
    hashFunc selfHashFunc;
    // variable of our hash function class.
    
    vector<list<ItemType>> hashTable;
    // it is my hashtable 





};



#endif
