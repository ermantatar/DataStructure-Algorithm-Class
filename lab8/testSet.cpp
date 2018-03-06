#include "Set.h"
#include<iostream>
#include<string>

int main() {
    Set set;
    // add items, including a duplicate
    set.add(345);
    set.add(235);
    set.add(23);
    set.add(500);
    set.add(3);
    set.add(235);
    // set should have 5 items: 3 23  235  345  500
    cout << "size: " << set.getSize() << endl;
    set.display(cout);
    // call find for each item in the set and for
    // some items not in the set.  output of 1 means
    // item was found, output of 0 means it was not
    // found
    cout << set.find(345) << endl;
    cout << set.find(250) << endl;
    cout << set.find(23) << endl;
    cout << set.find(3) << endl;
    cout << set.find(500) << endl;
    cout << set.find(67) << endl;
    cout << set.find(0) << endl;
    cout << set.find(235) << endl;
    // remove items including one not in the set
    set.remove(500);
    set.remove(400);
    set.remove(235);
    set.remove(3);
    set.remove(345);
    // set should have 1 item: 23
    cout << "size: " << set.getSize() << endl;
    set.display(cout);
}
