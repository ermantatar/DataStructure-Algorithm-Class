#ifndef BANKACCOUNT
#define BANKACCOUNT

#include<iostream>
#include <cstdlib>
#include <string>

using namespace std;

class BankAccount {
    // defines a data type to represent a bank account
    
public:
    BankAccount();
    // creates a BankAccount with a balance of 0
    
    BankAccount(string nameIn, double balanceIn, int idin);
    // creates a BankAccount with name and balance provided
    
    void deposit(double amount);
    // the balance has been incremented by amount
    
    void withdraw(double amount);
    // the balance has been decremented by amount
    
    string getName() const;
    // returns name
    
    double getBalance() const;
    // returns current balance
    
    friend ostream& operator<<(ostream & out, const BankAccount & b);
    // side effects: BankAccount information is sent to out
    
    
    
    
private:
    double balance;
    string name;
    int id;
};

#endif
