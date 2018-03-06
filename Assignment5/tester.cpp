#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>


using namespace std;

void display(queue<string> queue);

void writeFile(queue<string> lineInfo, queue<int> lineResults);
//side effects : creating  output file and changed it
// inputs are line onformations queue and results of lines.
// outputs are zero.
 

bool IsOperator();
// it will check item is operator or not
// input is ElementType item from Stack
//output is true or false
// there is no sideeffect.

bool checkPrecedence(string firstOpr, string secondOpr);
// inputs are two operator
// outputs are  boolean. true or false
// no sideeffect
int calculation(string opr, int firstOperand, int secondOperand);
// there is no side effect
//inputs are one operator and two operands.
// output is result of calculations.
int performOperation(queue<string> & queue);
// side effects changing the queue items. 
void readFile(string filename, string Line, string postfixLine); // it will return results of all lines.
// inputs are line, postfixline string to show lines.
// no outputs
// sideeffects changing value of strings 

int main(int argc, const char * argv[]) {
    
    string Line; // send to readFile
    string filename; // send to readFile
    string postfixLine; // send to readFile
    
    cout<< ">> Please write your file name ..." << endl;
    cin >> filename;
    
    
    readFile(filename, Line, postfixLine);
    
    



}

void writeFile(queue<string> lineInfo, queue<int> lineResults){

    ofstream outputfile("result.txt");
    
    if (outputfile.is_open()) {
        
        do{
        outputfile << "The postfix of " << lineInfo.front() << " #" << " is  =  "<<endl;
        lineInfo.pop();
        outputfile<< " >>>> "<< lineInfo.front() <<" The answer of the line is =  "<< lineResults.front() <<endl;
        lineInfo.pop();
        lineResults.pop();
        }while (!lineResults.empty() && !lineInfo.empty());
        outputfile.close();
    }
    else{
        cout<< "Output file cannot exist !! " << endl;
    }

    
}


bool IsOperator(string item){
    
    
    if (item == "+" || item == "*" || item == "-") {
        return true;
    }else
        return false;
}

bool checkPrecedence(string firstOpr, string secondOpr){
    if ( (firstOpr == "+" || firstOpr == "-") && secondOpr == "*") {
        return true;
    }else if( (firstOpr == "+" || firstOpr == "-"|| firstOpr == "*") && secondOpr == "("){
        return false;
    }
    else{
        return false;
    }

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

int performOperation(queue<string> & queue){

    
    
    string firstItem;
    int firstOperand = 0;
    int secondOperand = 0;
    stack<int> stackOperand;
    string oprt;
    
    
    while (!queue.empty()) {
        firstItem = queue.front();
        queue.pop();
      
        
        
        if (!IsOperator(firstItem)) {
            
            firstOperand = std::atoi(firstItem.c_str());
            secondOperand = std::atoi(queue.front().c_str());
            queue.pop();
            
            stackOperand.push(secondOperand);
            stackOperand.push(firstOperand);
            
        }
        else{
            oprt = firstItem;
            
            int operandFirst = stackOperand.top();
            stackOperand.pop();
            int operandSecond = stackOperand.top();
            stackOperand.pop();
            
           
            stackOperand.push(calculation(oprt, operandFirst, operandSecond));
            
        }
    
    }
    
    
    return stackOperand.top();

}


void readFile(string filename, string Line, string postfixLine){
    
    stack<string> stackOperators;
    
    queue<string> postfixQueue;
    
    queue<int> lineResults;
    
    queue<string> lineInfo;
    
    ifstream sourceFile;
    sourceFile.open(filename.c_str());
    
    if (sourceFile.is_open()) {
        
        
        while (!sourceFile.eof()) {
            
            string word;
            string line = "";
            getline(sourceFile, line);
            istringstream iss(line);
            
            
            do{
                iss>>word;
                
                
                
                if (word != "#") {
                    
                    Line = Line + " " + word;
                    
                    if (!IsOperator(word) && word != ")" && word != "(") {
                        
                        postfixLine = postfixLine + " " + word;
                        postfixQueue.push(word);
                    }
                    else if (word == "("){
                        
                        stackOperators.push(word);
                        
                    }
                    else if (word == ")"){
                        
                        
                        
                        while (stackOperators.top() != "(") {
                            
                            postfixQueue.push(stackOperators.top()); // it should return top element of stack.
                            postfixLine = postfixLine + " " + stackOperators.top();
                            
                            stackOperators.pop(); // after the send postfixQueue, we need to delete it.
                        }
                        
                        
                        stackOperators.pop(); // delete the left pharantesis.
                        
                        
                        
                    }else{
                        
                        if(!stackOperators.empty() && checkPrecedence(word, stackOperators.top())) {
                            postfixLine = postfixLine + " " + stackOperators.top();
                            postfixQueue.push(stackOperators.top());
                            
                            
                            stackOperators.pop();
                            stackOperators.push(word);
                        }
                        else if(!stackOperators.empty()){
                            //postfixLine = postfixLine + " " + stackOperators.top();
                            //postfixQueue.push(stackOperators.top());
                            stackOperators.push(word);
                        }else{
                        
                            stackOperators.push(word);
                        }
                        
                        
                    }
                    
                    
                    
                }else{
                    while(!stackOperators.empty()){
                        postfixQueue.push(stackOperators.top());
                        postfixLine = postfixLine + " " + stackOperators.top();
                        stackOperators.pop();
                    
                    }
                }
                
                
                
            
            }while (iss);
            
            
            
            
            if (postfixQueue.size() != 1) {
             

                lineResults.push(performOperation(postfixQueue));
                lineInfo.push(Line);
                lineInfo.push(postfixLine);
                
                
               // writeFile(Line, postfixLine, lineResults.top());    // delete after!!
                Line = "";
                postfixLine = "";    // clean the line info for next lines.
            
            }
            else{
                lineResults.push(std::atoi(postfixQueue.front().c_str()));
                lineInfo.push(Line);
                lineInfo.push(postfixLine);
                
                //  writeFile(Line, postfixLine, lineResults.top());   // delete after !!
                Line = "";
                postfixLine = "";   // clean the line info for next lines.
            }
            
            
            writeFile(lineInfo, lineResults);
            
            
        }// end of the while loop of EOF.
        
        
    }// end of the if source file is open.
    else{
        cout<< "The program could not reach your source file.. Sorry, Try Again!"<<endl;
    }
    sourceFile.close();
    
}

void display(queue<string> queue){

    while (!queue.empty()) {
        cout<<" > " <<queue.front()<<endl;
        queue.pop();
    }
    
    
    

}



