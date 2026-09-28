#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

using namespace std;


class BankAccount {
public:
    BankAccount();
    BankAccount(string accountNumber, string accountHolderName, double balance);
    // setters
    void setAccountNumberName(string accountNumberName);
    // getters
    string getAccountNumber();
    string getAccountNumberName();
    double getBalance();
    // extra
    void deposit(double amount);
    bool withdraw(double amount);
private:
    string accountNumber;
    string accountHolderName;
    double balance = 0.0;
};


#endif
