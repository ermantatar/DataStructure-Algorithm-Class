#include "MapHT.h"
#include<string>
#include<list>
#include<vector>
#include<algorithm>


using namespace std;

MapHT::MapHT(int tsize, hashFunc func){

    this->tsize = tsize;
    selfHashFunc = func;
    hashTable.resize(tsize);
    sizeMap = 0;
    
}

int MapHT::size(){
    return sizeMap;
}

bool MapHT::empty(){
    return (sizeMap==0);
}

double MapHT::loadFactor() const{

    return (double) sizeMap/tsize;

}

bool MapHT::addItem(const KeyType & key, const ValueType & value){

    
    
    if (!findItem(key)){
        
        int homeaddress = selfHashFunc(key, tsize);
        
        hashTable[homeaddress].push_back(make_pair(key, value));
        
        sizeMap++;
        
        return true;
    }
    return false;
 
}

bool MapHT::findItem(const KeyType & key){

    int homeaddress = selfHashFunc(key, tsize);
    
    list<ItemType> searchlist = hashTable[homeaddress];
    
    for(auto iter = searchlist.begin(); iter != searchlist.end(); iter++){
        
        if ((*iter).first == key){
            return true;
        }
    }

    return false;
}

ValueType MapHT::retrieveItem(KeyType key){



    int homeaddress = selfHashFunc(key, tsize);
    
    list<ItemType> searchlist = hashTable[homeaddress];
    
    
    for(auto iter = searchlist.begin(); iter != searchlist.end(); iter++){
        
        if (iter->first == key){
           
            return iter->second;
        }
    }
    cout<<endl;
   
    cout<< "There is no Bank Account with this ID.. Try Again.." <<endl;
    
    return NULL ;
}


ValueType MapHT::removeItem(KeyType & key)
    {
        int index = selfHashFunc(key,tsize);
        
        ValueType returnVal = NULL;
        
        for(auto iter = hashTable[index].begin() ; iter != hashTable[index].end() ; iter++)
        {
            if(iter->first == key)
            {
                returnVal = iter->second;
                hashTable[index].erase(iter);
                sizeMap--;
                return returnVal;
            }
        }
        cout<< "There is no Bank Account with this ID.. Try Again.." <<endl;
        return NULL;
}


void MapHT::displayItems(ostream & out){

    vector<list<ItemType>> displayTable = hashTable;
    vector<list<ItemType>>::iterator tableIter;
    
    list<ItemType>::iterator listIter;
    
    int homeaddress = 0;
    
    
    
    for(auto tableIter =  displayTable.begin(); tableIter != displayTable.end(); tableIter++){
        
        list<ItemType> displayList = hashTable[homeaddress];
        
        
        
        if(displayList.size() != 0){
            
            for(listIter = displayList.begin(); listIter != displayList.end(); listIter++ ){
        
                out << *(listIter->second);
        
            }
        }
        
        homeaddress++;
    
    }


}


unsigned long MapHT::longestListLenght(){


    
    vector<list<ItemType>> displayTable = hashTable;
    vector<list<ItemType>>::iterator tableIter;
    
    int homeaddress = 0;
    unsigned long maxSize= hashTable[0].size();                       // ask this ???
    
    
    
    for(auto tableIter =  displayTable.begin(); tableIter != displayTable.end(); tableIter++){
        
        list<ItemType> displayList = hashTable[homeaddress];
     
        if(maxSize < displayList.size()){
        
            maxSize = displayList.size();
        }
        homeaddress++;
    }
    return maxSize;
}


double MapHT::averageListLenght(){

    vector<list<ItemType>> displayTable = hashTable;
    vector<list<ItemType>>::iterator tableIter;
    
    list<ItemType>::iterator listIter;
    
    int homeaddress = 0;
    double totalItem = 0.0;
    double totalList= 0.0;
    
    
    for(auto tableIter =  displayTable.begin(); tableIter != displayTable.end(); tableIter++){
        
        list<ItemType> displayList = hashTable[homeaddress];
        
        
        
        if(displayList.size() != 0){
            
            totalList++;
            
            for(listIter = displayList.begin(); listIter != displayList.end(); listIter++ ){
                
                totalItem++;
                
            }
        }
        
        homeaddress++;
        
    }

    return double (totalItem / totalList) ;

}



void MapHT::displayStats(ostream & out){
    
    out<<endl; // to see clear output

    out << "Load Factor of Hash Table is : " << loadFactor() << endl;
    
    out<< "The Longest Synonym list size is " << longestListLenght() << endl;
    
    out << "The Average Synonym list lenght  is " << averageListLenght() << endl;
    
    out <<endl;   // to see clear output
}






