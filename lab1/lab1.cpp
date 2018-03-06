#include <iostream>
using namespace std;

/* Program to demonstrate use of functional decomposition,
   program organization and style standards required for
   all programs written for CS240C.  Program prompts user
   for 2 integers and displays their average.
*/	

int getNumber();
// input: none
// output: returns an integer value
// side effects: prompts user to enter an integer
	
double findAverage(int num_1, int num_2);
// input: 2 integer values
// output: returns the average of num_1 and num_2
// side effects: none

void display(double average);
// input: the average
// output: none
// side effects: displays average on the screen	

int main ( ) {

    int a, b;
    double average;
    cout<<"Give me the first number";
    a = getNumber();
    cout<<"Give me the second number";
    b = getNumber();
    average = findAverage(a,b);
    display(average);

    return 0;
}

// define the 3 functions whose prototypes/declarations appear above
int getNumber(){
    int num1;

    cout<<"Enter an integer!";
    cin>>num1;

    return num1;

}
double findAverage(int num_1, int num_2){


    double average = ((double)(num_1 + num_2)/2);
    return average;
}
void display(double average){

    cout<<"average is " << average << endl;

}
