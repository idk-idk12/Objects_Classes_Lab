#include "BankAccount.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;


void my_cin(int &x) {
    // this handles non-int inputs
    if (!(cin >> x)) {
	// these two lines clears the buffer and ensures that the user can input again.
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

bool my_cin(double &x) {
    // this handles non-int inputs
    if (!(cin >> x)) {
	// these two lines clears the buffer and ensures that the user can input again.
	cout << "Amount must be a number." << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return false;
    }
    return true;
}

void display_menu(int& user_choice) {
    cout << "1. Create Account" << endl;
    cout << "2. Change Account Name" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. View Account Details" << endl;
    cout << "6. View All Accounts" << endl;
    cout << "7. Quit" << endl;
    my_cin(user_choice);
}


int get_account(vector<BankAccount>& accounts) {
    string account_num;
    cout << "Account number: ";
    cin >> account_num;
    for (int i = 0; i < accounts.size(); ++i) {
	if (accounts.at(i).getAccountNumber() == account_num) {
	    return i;
	}
    }
    cout << "Account '" << account_num << "' not found" << endl;
    return -1;
}


void add_account(vector<BankAccount>& accounts) {
    string account_name;
    double initial_balance;
    cout << "Account name: ";
    cin >> account_name;
    cout << "Initial amount: $";
    cin >> initial_balance;
    BankAccount account(to_string(accounts.size()+1), account_name, initial_balance);
    accounts.push_back(account);
}


void change_account_name(vector<BankAccount>& accounts) {
    int account_idx = get_account(accounts);
    if (account_idx != -1) {
	BankAccount& account = accounts.at(account_idx);
	string new_account_name;
	cout << "New account name: ";
	cin >> new_account_name;
	account.setAccountNumberName(new_account_name);
    }
}


void deposit(vector<BankAccount>& accounts) {
    int account_idx = get_account(accounts);
    if (account_idx != -1) {
	// without the '&' it creates a copy of the account object, and thus will not see any change after this function.
	BankAccount& account = accounts.at(account_idx);
	double amount;
	cout << "Deposit amount: $";
	if (my_cin(amount)) {
	    account.deposit(amount);
	}
    }
}


void withdraw(vector<BankAccount>& accounts) {
    int account_idx = get_account(accounts);
    if (account_idx != -1) {
	BankAccount& account = accounts.at(account_idx);
	double amount;
	cout << "Withdraw amount: $";
	if (my_cin(amount)) {
	    if (account.withdraw(amount)) {
		cout << "Successfully withdrew specified amount from account." << endl << endl;
	    }
	    else {
		cout << "Insufficient funds in account to withdraw specified amount." << endl << endl;
	    }
	}
    }
}


void get_account_details(vector<BankAccount>& accounts) {
    int account_idx = get_account(accounts);
    if (account_idx != -1) {
	BankAccount account = accounts.at(account_idx);
	cout << "Account name: " << account.getAccountNumberName() << endl;
	cout << "Account balance: $" << account.getBalance() << endl;
    }
}


void get_all_account_details(vector<BankAccount>& accounts) {
    for (BankAccount account : accounts) {
	cout << "Account number: " << account.getAccountNumber() << endl;
	cout << "Account name: " << account.getAccountNumberName() << endl;
	cout << "Account balance: $" << account.getBalance() << endl << endl;
    }
}


int main() {
    int user_choice;
    vector<BankAccount> accounts;
    do {
	display_menu(user_choice);
	cout << endl;
	switch (user_choice) {
	    case 1:
		add_account(accounts);
		break;
	    case 2:
		change_account_name(accounts);
		break;
	    case 3:
		deposit(accounts);
		break;
	    case 4:
		withdraw(accounts);
		break;
	    case 5:
		get_account_details(accounts);
		break;
	    case 6:
		get_all_account_details(accounts);
		break;
	    case 7:
		cout << "Quitting" << endl;
		break;
	    default:
		cout << "Only 1-7 options are avaliable." << endl;
		break;
	}
	cout << endl;
    }
    while (user_choice != 7);
    return 0;
}
