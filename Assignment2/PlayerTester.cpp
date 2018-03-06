
#include <iostream>
#include "player.h"
#include "SimpleList.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>



using namespace std;

void openFile(SimpleList & listObject);
void screenMenu(SimpleList & listObject);
void showList(SimpleList & listObject);

int main(){
    
    SimpleList listObject;
    
    
    openFile(listObject);
    // it will open the file
    // input is object of the SimpleList class
    // it is void function, it mainly open the file and it changes listObject items(adding items)
    screenMenu(listObject);
    // it will show the menu
    // it takes listObject to be input
    // it is void function and I changed some variable
    
    showList(listObject);
    //after the exit program I am asking the user do you wanna see all list.
    
    
    
    
    
   
    
    
    
    
    return 0;
}



void openFile(SimpleList & listObject){
    
    // test array!
    
    TennisPlayer playerArray[20];
    
    
    string sentence;
    string line[5];

    
    ifstream myfile;
    myfile.open("players.txt");
    
    
    if(myfile.is_open()){
        
        
        for (int i = 0; i<20 ; i++){
            getline(myfile, sentence);
            
            istringstream iss(sentence);
            int counter = 0;
            string word;
            
            do
            {
                iss >> line[counter];
                counter++;
                if(counter == 6){
                    line[3] += " " + line[4];
                }
                
                
            } while(iss);
            
            //Converts the totalPoint string to integer.
            string converter;
            converter = line[2];
            int valueOfLine2 = atoi(converter.c_str());
            
            // Getting players in list.
            TennisPlayer player(line[0], line[1], (int)(i+1), valueOfLine2,line[3]);
            playerArray[i] = player;
            
            
            
            listObject.insert(player, i);
            
            
        }
        
        /* emirin yoluda 2 kere govdeyi yazmak ve isim soy ad atamak!
         string word;
         while(myfile >> word){
         
         cout << word << "\n";
         } */
    }
    myfile.close();
    
    

}

void screenMenu(SimpleList & listObject){
    
    int x = 0;
    int rank;
    string name;

    while (x != 4){
        cout<< endl << "Please choose number for searching your player information"<< endl;
        cout<< endl;
        cout<< "1- Which player is ranked at a given position?" <<endl;
        cout<< "2- What is the ranking of player with a given last name?" << endl;
        cout<< "3- How many points are there between two spesific position?" << endl;
        cout<< "4- Exit the program.."<<endl;
        
        cin>>x;
        
        if( x==1){
            cout<< "Please give a rank?"<< endl;
            cin>> rank;
            if ((rank<0) || (rank>20)){
                cout<< "Please enter a rank between 1-20.."<< endl;
                cin>>rank;
                
                 for(int i = 0; i< listObject.listSize(); i++){
                     if (listObject.retrieve(i).getRanking() == rank){
                         cout << listObject.retrieve(i);
                     }
                 }
                
            }else{
                for(int i = 0; i< listObject.listSize(); i++){
                    if (listObject.retrieve(i).getRanking() == rank){
                        cout << listObject.retrieve(i);
                    }
                }

            }
            
            
        } //end of the searching choice 1!
        
        else if ( x== 2){
        
            cout<< "Please give the lastname of your player to find player rank! .."<< endl;
            cin>>name;
            
            
            
            
            for(int a = 0; a < listObject.listSize(); a++){
                
                string temp1 = listObject.retrieve(a).getLastName();
                
                if(temp1.compare(name)){
                    
                    cout<< listObject.retrieve(a).getLastName();
                
                }
                
            
            }
            
            
        
        
        
        }
        
        else if (x == 3){
            
            int position1;
            int position2;
            int pointdifference;
            
            cout<< "Please give your the first spesific position.. "<< endl;
            cin>>position1;
            cout<<"Please give your the second spesific position.."<< endl;
            cin>> position2;
            
            pointdifference = ( listObject.retrieve(position1).getpointTotal() - listObject.retrieve(position2).getpointTotal() );
            
            cout<<"Point Difference is : "<< pointdifference << endl;
        
        
        
        }
        
        
        
        
        
    }


}

void showList(SimpleList & listObject){

    string decision;
    cout<<endl;
    cout<<"You Exitted!"<<endl;
    cout<<"Do you want to see all list ?" << endl;
    cout<<endl;
    cin>>decision;
    
    if (decision.compare("y")|| decision.compare("Y")){
        
        listObject.display(cout);
    }else{
        cout<<"Okay, See you again.."<<endl;
    }

}

