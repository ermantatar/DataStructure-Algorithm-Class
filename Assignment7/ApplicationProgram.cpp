#include <iostream>
#include "BankAccount.h"
#include "MapHT.h"

#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

void displayHelper(KeyType & id, MapHT & Bank);
// it is for my display choice in user inter face, inputs are address of Bank Account ID
// and address of Map of Bank
// output is none
// side effects is display the object on the screen!
void closeAccount(KeyType & id, MapHT & Bank);
// it is kind of helper function for my closeAccount and inputs are address of the Bank Account ID
// output is none
// side effects is deleting pointer which is pointing to Bank Account with associated id.
void accountWorks(MapHT & Bank, int selection);
// it is for user interface function, will pick what user wants to do.
// inputs are address of Bank Map, and copy of selection variable
// side effect is none.

void printUserInterface(MapHT & Bank);
// it is user interface
// input is address of Bank Map
//output is none
// side effects is displaying menu on screen.
void readFile(MapHT & Bank);
// input is adress of Bank Map
// output is none.
// side effects is bank object will changing by adding item inside it.

int hashFunction(KeyType key, int tsize);


int main(){
    
    
   // MapHT Bank(10, hashFunction);
    
   // readFile(Bank);
   // Bank.displayItems(cout);
   // Bank.displayStats(cout);
	//    while(1)
       // printUserInterface(Bank);
    
    string x; 

	cout << "HELLO ERMAN, I FOUND SOME MACS AROUND YOU, DO YOU WANNA HACK THEM ??  " << endl;
	cin >> x;

	if(x=="yes"){
		cout<< "DO YOU WANNA HACK CANSU MAC'S ?"<<endl;
		cin>>x;
		if(x=="yes"){
		cout<< "DO YOU WANNA STEAL CANSU INFORMATION ??" <<endl;
		cin >> x;
		if(x=="no"){
			cout<< "DO YOU WANNA SEE CANSU PHOTOS ??" <<endl;
			cin>>x;
			if(x=="no"){
				cout<<"SHE IS LUCKY! SEE YOU LATER ERMAN! !!"<<cout;
			
			}
		}
		}
	}

   
    


}


int hashFunction(KeyType key, int tsize){

    
    
    /*
     // turn key to string and calculate it like that.  
     
    const unsigned long BIG_PRIME = 4294967291;
    int address = 0;
    
    for (int i = 0; i < key.length(); i++)
       
        address = address * 13 + key[i];
    
    return (address * BIG_PRIME) % tsize;
    */
    
    
    return key % tsize;
    }

void printUserInterface(MapHT & Bank){

    int selection;
   cout <<endl;
   cout << "----------------------------------------------------" << endl;
   cout << "                 BANK OF BINGHAMTON                 " << endl;
   cout << "____________________________________________________" << endl;
   cout << endl;

    cout << " ***** "<<endl;
    cout << " * 1 * DEPOSIT TO ACCOUNT " << endl;
    cout << " ***** "<<endl;
    cout <<endl;
    cout << " ***** "<<endl;
    cout << " * 2 * WITHDRAW FROM ACCOUNT " << endl;
    cout << " ***** "<<endl;
    cout <<endl;
    cout << " ***** "<<endl;
    cout << " * 3 * DISPLAY MY ACCOUNT  " << endl;
    cout << " ***** "<<endl;
    cout <<endl;
    cout << " ***** "<<endl;
    cout << " * 4 * CLOSE MY ACCOUNT " << endl;
    cout << " ***** "<<endl;
    cout <<endl;
    cout << " ***** "<<endl;
    cout << " * 5 * EXIT " << endl;
    cout << " ***** "<<endl;


    cin>> selection;
    
    accountWorks(Bank,selection);
    
    
}

void accountWorks(MapHT & Bank, int selection){
    
    int id;
    double money = 0.0;
    
    switch(selection){
    
        case 1:
        {
            cout <<endl;
            cout << " ********************* "<<endl;
            cout << "     ENTER YOUR ID : " << endl;
            cout << " ********************* "<<endl;
            cout <<endl;
            cin >> id;
            cout << " ********************* "<<endl;
            cout << "     HOW MUCH YOU WANT TO ADD ? : " << endl;
            cout << " ********************* "<<endl;
            cout <<endl;
            cin >> money;
            Bank.retrieveItem(id)->deposit(money);
            break;
        }
        case 2:
        {
            cout <<endl;
            cout << " ********************* "<<endl;
            cout << "     ENTER YOUR ID : " << endl;
            cout << " ********************* "<<endl;
            cout <<endl;
            cin>> id;
            cout << " ************************************* "<<endl;
            cout << "     HOW MUCH YOU WANT TO WITHDRAW ? : " << endl;
            cout << " ************************************* "<<endl;
            cout <<endl;
            cin>> money;
            Bank.retrieveItem(id)->withdraw(money);
            break;
        }
        case 3:
        {
            cout <<endl;
            cout << " ********************* "<<endl;
            cout << "     ENTER YOUR ID   : " << endl;
            cout << " ********************* "<<endl;
            cout <<endl;
            cin>>id;
            displayHelper(id, Bank);
            break;
        }
        case 4:
        {
            cout <<endl;
            cout << " ****************************************** "<<endl;
            cout << "     TO CLOSE YOUR ACCOUNT, ENTER YOUR ID : " << endl;
            cout << " ****************************************** "<<endl;
            cout <<endl;
            cin>> id;
            closeAccount(id, Bank);
            break;
        }
        case 5:
        {
            cout <<endl;
            cout << " ************************************************************* "<<endl;
            cout << "     THANKS FOR WORKING WITH US, ENJOY THE REST OF YOUR DAY! : " << endl;
            cout << " ************************************************************* "<<endl;
            cout <<endl;
            exit(EXIT_SUCCESS);
            break;
        }
    }


}


void readFile(MapHT & Bank){

    string line;
    ifstream file ("accounts.txt");
    
    if(file.is_open()){
    
        while(getline(file, line)){
            
            istringstream iss(line);
            
            string accountName;
            int accountID;
            string token;
            iss >> accountID;
            
            while(iss >> token){
                if(token != ","){
                    accountName = accountName + " " + token;
                }
            }
            
            BankAccount *account = new BankAccount(accountName, 0.0, accountID);
            Bank.addItem(accountID, account);
            
        
        }
    
    
    }





}

void closeAccount(KeyType & id, MapHT & Bank){

    ValueType deleteValue = Bank.removeItem(id);
    
    delete deleteValue;
    
    return;
    
}

void displayHelper(KeyType & id, MapHT & Bank){

    if(Bank.retrieveItem(id) == NULL){
        cout <<endl; // to see clear output!
       
        cout<<endl; // to see clear output
        return;
    
    }else{
        cout << *(Bank.removeItem(id)) << endl;
        return;
    }

}
