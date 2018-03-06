#include "SimpleListL.h"


void testPhase1Methods(const SimpleList & sl);
// input: a SimpleList
// output: none
// side effects: displays test results on screen


int main(){
    SimpleList l;
    testPhase1Methods(l);
    l.append(76);
    l.append(36);
    cout << "after 2 appends" << endl;
    testPhase1Methods(l);
}

void testPhase1Methods(const SimpleList & sl){
    if(sl.empty())
        cout << "list is empty: " << endl;
    else
        cout << "list is not empty" << endl;
    cout << "size of list is: " << sl.listSize() << endl;
    cout << "contents of list: " << endl;
    sl.display(cout);
}
