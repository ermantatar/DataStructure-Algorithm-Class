#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>


using namespace std;

void writeFile(Stack & results, string filename);
// it will write the file that I created before to keep results in a file.
// input is the stack of results and filename that we want to read because I will first write line information.
// output is none.
// sideeffect is stack object is changing when writeFile function calls


int calculation(string opr, int firstOperand, int secondOperand);
// it will calculate the calculations depend on the operand
// inputs are operands and operators.
// output is result of the calculations
// Printing in else statement can be tought ss a sideeffect,
// if there is no valid operand it will print "invalid Operand"

Stack converter(Stack & resultStack);
// It will reverse the order in the resultStack to send writeFile function.
// input is resultStack that includes results from calculations
// output is the new Stack that has resultStack item with reversing order.
// SideEffect, resultStack is changing it will give all items to new Stack


bool IsOperator(ElementType item);
// it will check item is operator or not
// input is ElementType item from Stack
//output is true or false
// there is no sideeffect.

int performOperation(Queue & queue);
// it will calculate post fix calculations
// input is the line queue
// output is the line result.
// sideeffect is queue is changing during the this functions.

Stack readFile(string filename);
// it will read from file that user entered
//input is name of the file we want to read.
// output is the stack of results.
// it will write object of Queue class.






int main(int argc, const char * argv[]) {
    
    string filename;
    cout<< "Please write a file name for the program "<<endl;
    cin>> filename;
    


    Stack results = readFile(filename);
   
 
    Stack convertResults = converter(results); // I need to reverse the order here

    writeFile(convertResults,filename);
    
    
    
    
    
    return 0;
}

Stack converter(Stack & resultStack){

    Stack newStack;
    resultStack.pop(); // I deleted last zero, end of the all the line. 
 
    while (!resultStack.empty()) {
        
        newStack.push(resultStack.pop());
    }


    return newStack;

}



Stack readFile(string filename){
    Stack results;
    Queue  queue;
    
    ifstream myfile;
    myfile.open(filename.c_str());
    
    if(myfile.is_open()){
        
        while (!myfile.eof()) {
            
            string line= "";
            getline(myfile, line);
            istringstream iss(line);
            string word;
            do{
            
                iss>> word;
                if (word != "#") {
                    
                    queue.enqueue(word);
                }
                
                
            
            }while(iss);
          
            if (queue.QSize()!=1) {
                
                results.push(performOperation(queue));
            }
            else{
                
                results.push(std::atoi(queue.dequeue().c_str()));
            }
            
            
        }
    
    
    }else{
        cout<< "Unable to read your file!"<<endl;
    }
    
    
    myfile.close();
    
    return results;

}

int performOperation(Queue & queue){

    string firstItem;
    int firstOperand = 0;
    int secondOperand = 0;
    Stack operandstack;
    
    string oprt;
    
    while (!queue.Qempty()) {
        
        firstItem = queue.dequeue();
    
        if(  !IsOperator(firstItem) ){
            
    
            firstOperand = std::atoi(firstItem.c_str());
            
            
            secondOperand = std::atoi(queue.dequeue().c_str());
            
        
            operandstack.push(firstOperand);
            operandstack.push(secondOperand);
            

            
        }else{
            oprt = firstItem;
            operandstack.push(calculation(oprt, operandstack.pop(), operandstack.pop()));
           
        }
        
        
        
    }
    return operandstack.pop();

}

bool IsOperator(ElementType item){
    
    
    if (item == "+" || item == "*" || item == "-"|| item == "#") {
        return true;
    }else
        return false;
}

int calculation(string opr, int firstOperand, int secondOperand){

    
    if (opr == "+") {
        return firstOperand + secondOperand;
    }
    else if(opr == "*"){
        return firstOperand * secondOperand;
    }
    else if (opr == "-"){
        return firstOperand - secondOperand;
    }else if(opr == "#"){
        return 0;
    }
    else{

        cout<< "Invalid Operator!";
    }

    return -1;
}

void writeFile( Stack & results, string filename){
    
    ofstream myfile("Result.txt");
    ifstream myreadfile;
    myreadfile.open(filename.c_str());
    string line;



    if (myfile.is_open() && myreadfile.is_open()){
        while(!results.empty()){

            getline(myreadfile,line);
            myfile<<line << " = "<<results.pop()<<endl;

        }
        myfile.close();
    }
    else{
        cout<< "File is not exist !!"<< endl;
    }

}

