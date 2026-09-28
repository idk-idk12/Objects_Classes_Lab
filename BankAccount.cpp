#include "BankAccount.h"

using namespace std;


BankAccount::BankAccount(string accountNumber, string accountHolderName, double balance) {
    this->accountNumber = accountNumber;
    this->accountHolderName = accountHolderName;
    this->balance = balance;
}

void BankAccount::setAccountNumberName(string accountHolderName) {
    this->accountHolderName = accountHolderName;
}

string BankAccount::getAccountNumber() {
    return accountNumber;
}

string BankAccount::getAccountNumberName() {
    return accountHolderName;
}

double BankAccount::getBalance() {
    return balance;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

bool BankAccount::withdraw(double amount) {
    if ((balance - amount) >= 0) {
	balance -= amount;
	return true;
    }
    return false;
}

