#include "PQueue.h"
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdio.h>
using namespace std;

PQueue::PQueue(){
    sizeQ = 0;
}

int PQueue::size() const {
    return sizeQ;
}

bool PQueue::empty(){
    return(sizeQ==0);
}

void PQueue::enqueue(ItemType & item){
    
    jobs.push_back(item);
    sizeQ++;
    
    if (sizeQ > 0)
        addHeapOrder(sizeQ-1);
    return;
}

void PQueue::addHeapOrder(int index){
    
    if( index >= 0 && jobs[ (index - 1) / 2]->getPriorty() > jobs[index]->getPriorty() ){
        swap( jobs[ (index - 1) / 2], jobs[index]);
        addHeapOrder((index-1)/2);
    }
    return;
    
}

void PQueue::deleteHeapOrder(int index){
    
    if(sizeQ <= (2*index)+1){
        return;
    }
    else{
        
        if(jobs[(2*index)+1]->getPriorty()  <= jobs[(2*index)+2]->getPriorty()){
        
        swap(jobs[(2*index)+1] , jobs[index]);
        deleteHeapOrder((2*index)+1);
        }
        else{
    
        swap(jobs[(2*index)+2] , jobs[index]);
        deleteHeapOrder((2*index)+2);
        
        }
    }
}

void PQueue::dequeue(){

    if(sizeQ == 0){
        return;
    }
    else{
    
        jobs[0] = jobs[ sizeQ-1];
        sizeQ--;
        deleteHeapOrder(0);
    
    }

}


ItemType& PQueue::front(){

    return jobs[0];

}
