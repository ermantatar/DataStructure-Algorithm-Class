// SimpleListDTester.cpp

#include "SimpleListD.h"
#include<iostream>
using namespace std;

void testAssignmentOp();
// create 2 lists and assign one to the other

void testCopyConstructor(SimpleList sl);
// pass a list as a value parameter

int main(){
	
	// create a list to send to testCopyConstructor
	int capacity = 5;
	SimpleList sl(capacity);
	sl.insert(34, 0);
	sl.insert(3, 0);
	sl.insert(56, 1);
	sl.insert(123, 0);
	cout << "contents of list before calling testCopyConstructor" << endl;	
	cout << "should be: 123, 3, 56, 34" << endl;
	sl.display(cout);
	testCopyConstructor(sl);	
	cout << "contents after calling testCopyConstructor" << endl;	
	cout << "should be: 123, 3, 56, 34" << endl;
	sl.display(cout);
	
	testAssignmentOp();
}

void testCopyConstructor(SimpleList sl){
	cout << "constents of list passed to testCopyConstructor" << endl;
	cout << "should be: 123, 3, 56, 34" << endl;
	sl.display(cout);
	sl.remove(0);
	sl.insert(500, 0);
	cout << "contents of list after replacing first item with 500" << endl;
	cout << "should be: 500, 3, 56, 34" << endl;
	sl.display(cout);
}

void testAssignmentOp(){
	SimpleList sl1(3);
	sl1.insert(22, 0);
	sl1.insert(36, 1);
	SimpleList sl2(5);
	sl2.insert(89,0);
	sl2.insert(99, 1);
	sl2.insert(78,2);
	cout << "contents of sl1" << endl;
	cout << "shoud be: 22, 36" << endl;
	sl1.display(cout);
	cout << "contents of sl2" << endl;
	cout << "shoud be: 89, 99, 78" << endl;
	sl2.display(cout);
	
	sl2 = sl1;
	
	cout << "contents of sl2 after: sl2 = sl1;" << endl;
	cout << "shoud be: 22, 36" << endl;
	sl2.display(cout);
	cout << "contents of sl1 after: sl2 = sl1" << endl;
	cout << "shoud be: 22, 36" << endl;
	sl1.display(cout);
	
	sl2.insert(500,0);
	
	cout << "contents of sl2 after: sl2.insert(500, 0)" << endl;
	cout << "shoud be: 500, 22, 36" << endl;
	sl2.display(cout);
	cout << "contents of sl1 after: sl2.insert(500, 0" << endl;
	cout << "shoud be: 22, 36" << endl;
	sl1.display(cout);
	cout << endl;
}

	
	
	
	
