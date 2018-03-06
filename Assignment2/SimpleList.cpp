
#include <cassert>
#include "SimpleList.h"

SimpleList::SimpleList(){
    size = 0;
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

