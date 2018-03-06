#include "BankAccount.h"
#include<vector>
#include<algorithm>

void displayAccounts(vector<BankAccount> bank);
// input: a vector of BankAccounts
// output: none
// side effects: displays all BankAccounts on screen

bool compareNames(const BankAccount & acct1, const BankAccount & acct2);
// input: 2 BankAccount objects
// output: true if the name of acct1 is alphabetically less than the name of acct2
// side effects: none

int main(){
	vector<BankAccount> bank;
	bank.push_back(BankAccount("Joe",45));
	bank.push_back(BankAccount("Brian", 100));
	bank.push_back(BankAccount("Bryan", 101));
	bank.push_back(BankAccount("Erman", 99));
	
	//sort(bank.begin(), bank.end());
	

	


	//---> CREATE AND ADD MORE BANK ACCOUNT OBJECTS HERE
	
	
	cout << "Bank contains the following accounts" << endl;
	displayAccounts(bank);

	//---> SORT THE ACCOUNTS BASED ON THEIR BALANCE HERE
	//---> BankAccount's operator< will be used to do the sorting
	
	
	cout << "Accounts after sorting by balance" << endl;
	sort(bank.begin(), bank.end());
	displayAccounts(bank);


	//---> SORT THE ACCOUNTS BASED ON THEIR NAME HERE
        //---> use the compareNames function to do the sorting
	
	
	cout << "Accounts after sorting by name" << endl;
	sort(bank.begin(), bank.end(), compareNames);
	displayAccounts(bank);
	
	
	//---> FIND THE ACCOUNT WITH THE HIGHEST BALANCE HERE
	
	
	
	cout << "Account with highest balance" << endl;
	cout << *max_element(bank.begin(), bank.end());
}

void displayAccounts(vector<BankAccount> bank){
	
	vector<BankAccount>::iterator iter = bank.begin();

	for(iter; iter != bank.end() ; iter++){

		cout<< *iter << endl;
	}


}

bool compareNames(const BankAccount & acct1, const BankAccount & acct2){
	if(acct1.getName() < acct2.getName()){
		return true;
	}else
		return false;

}


//---> DEFINE THE CompareNames FUNCTION HERE
	

