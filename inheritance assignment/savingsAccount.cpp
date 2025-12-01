#include "savingsAccount.h"
#include <iostream>

// Default constructor
savingsAccount::savingsAccount() = default;

// Constructor with parameters
savingsAccount::savingsAccount(int accountNumber, double balance, double interestRate)
    : bankAccount(accountNumber, balance), interestRate(interestRate) {}

// Set interest rate
void savingsAccount::setInterestRate(double rate) {
    interestRate = rate;
}

// Get interest rate
double savingsAccount::getInterestRate() const {
    return interestRate;
}

// Apply interest to the account
void savingsAccount::postInterest() {
    double interest = getAccountBalance() * (interestRate / 100.0);
    deposit(interest);
}

// Withdraw override with basic validation
void savingsAccount::withdraw(double amount) {
    if (amount < 0) {
        std::cout << "Error: Withdraw amount must be positive.\n";
        return;
    }

    if (amount > getAccountBalance()) {
        std::cout << "Error: Insufficient funds.\n";
        return;
    }

    bankAccount::withdraw(amount);
}

// Display account information
void savingsAccount::print() const {
    std::cout << "=== Savings Account Information ===\n";
    bankAccount::print();
    std::cout << "Interest Rate: " << interestRate << "%\n";
}