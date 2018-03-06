#include "Set.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

void readFiles();
//there is no input parameter. 
// output also is none.
// side effects are  it is creating Set object and  it is changing its members. and display the screen!

int main() {
    
    readFiles();
    
    
    
    
}

void readFiles(){
            
    Set spammersTree;
    int spammerCounter = 0;
    int checkCounter = 0;
    
    ifstream inputRemove;
    string filename3;
    
    ifstream inputcheck; // for the check file.
    string filename2;

    ifstream inputFile; // for the spammers file.
    string filename;
    
    
    cout<< "Please write your spammer file"<<endl;
    cin>>filename;
    
    inputFile.open(filename.c_str());
    
    if(inputFile.is_open()){
	    
        string line = "";
        while(getline(inputFile, line)){
        
            
            spammersTree.add(line);
            
        
        
        }
    
    }else{
    
        cout<< "Computer could not read your Spammers file" << endl;
    }
    
    
    cout << "THE SPAMMERS TREE SIZE IS : " << spammersTree.getSize() << endl;
    cout << "THE HEIGHT OF THE SPAMMERS TREE IS : " << spammersTree.height() << endl;
    cout << "THE CONTENT OF THE SPAMMERS TREE IN ASCENDING ORDER IS : " << endl;
    spammersTree.display(cout);
    
    
    
    
    
    cout << "Please enter your Check Files" << endl;
    cin >> filename2;
    
    inputcheck.open(filename2.c_str());
    
    if (inputcheck.is_open()){
    
        while(!inputcheck.eof()){
        
            string line = "";
            getline(inputcheck, line);
            checkCounter++;     // it will count how many item check file have.
            
            if(spammersTree.find(line)){
            
                spammerCounter++;
            }
        
        
        }
    }else{
    
        cout << "Computer could not find your Check File" << endl;
    }
    
    cout << "IN YOUR CHECK FILE, YOU HAVE " << spammerCounter << " BAD SPAMMERS IP ADDRESSES" << endl;
    cout << "IN YOUR CHECHK FILE, YOU HAVE " << (checkCounter - spammerCounter) << " GOOD IP ADDRESSES" << endl;
    
    
    cout << "Plese enter your Remove Files "<< endl;
    cin >> filename3;
    
    inputRemove.open(filename3.c_str());
    
    if(inputRemove.is_open()){
        
        while(!inputRemove.eof()){
            
            string line = "";
            getline(inputRemove, line);
            
            spammersTree.remove(line);
        
        }
    }
    else{
    
        cout<<"Computer could not find your Remove File" << endl;
    }
    
    cout<< " _____After the remove addresses from the  spammers tree_____ " <<endl;
    
    cout<< "SIZE OF THE SPAMMERS THREE IS : " << spammersTree.getSize() << endl;
    cout<<" THE HEIGHT OF THE TREE IS : " << spammersTree.height() << endl;
    cout<< "THE CONTENTS OF THE SPAMMER TREE ARE :"<< endl;
    
    spammersTree.display(cout);
    
    
}
