// BankAccount.cpp

#include "BankAccount.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

BankAccount::BankAccount(){
    name = "anonymous";
    balance = 0.0;
    id = 000000;
}

BankAccount::BankAccount(string nameIn, double balanceIn, int idin){
    name = nameIn;
    balance = balanceIn;
    id = idin;
}

void BankAccount::deposit (double amount){
    balance += amount;
}

void BankAccount::withdraw (double amount){
    balance -= amount;
}

string BankAccount::getName () const{
    return name;
}

double BankAccount::getBalance () const{
    return balance;
}

ostream& operator<<(ostream & out, const BankAccount & b){
    out << " ID : "<<b.id <<"          "<<"FULL NAME : "<< b.name << "         " <<"BALANCE >> "<<b.balance << endl;
    return out;
    // *************** it was not problem in lab7 , but now it required return out.
}



