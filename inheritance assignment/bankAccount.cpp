#include "bankAccount.h"
#include <iostream>

// Default constructor
bankAccount::bankAccount() = default;

// Constructor with parameters
bankAccount::bankAccount(int accountNumber, double balance)
    : accountNumber(accountNumber), balance(balance) {}

// Setter for account number
void bankAccount::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}

// Getter for account number
int bankAccount::getAccountNumber() const {
    return accountNumber;
}

// Getter for balance
double bankAccount::getAccountBalance() const {
    return balance;
}

// Deposit money into the account
void bankAccount::deposit(double amount) {
    if (amount < 0) {
        std::cout << "Error: Deposit amount must be positive.\n";
        return;
    }
    balance += amount;
}

// Withdraw money from the account (base version)
void bankAccount::withdraw(double amount) {
    if (amount < 0) {
        std::cout << "Error: Withdraw amount must be positive.\n";
        return;
    }
    balance -= amount;
}

// Print basic account information
void bankAccount::print() const {
    std::cout << "Account Number: " << accountNumber << '\n';
    std::cout << "Balance: $" << balance << '\n';
}