#include "checkingAccount.h"
#include <iostream>

// Default constructor
checkingAccount::checkingAccount() = default;

// Constructor with parameters
checkingAccount::checkingAccount(int accountNumber, double balance,
                                 double interestRate, double minimumBalance,
                                 double serviceCharges)
    : bankAccount(accountNumber, balance),
      interestRate(interestRate),
      minimumBalance(minimumBalance),
      serviceCharges(serviceCharges) {}

// Set interest rate
void checkingAccount::setInterestRate(double rate) {
    interestRate = rate;
}

// Get interest rate
double checkingAccount::getInterestRate() const {
    return interestRate;
}

// Set minimum balance
void checkingAccount::setMinBalance(double amount) {
    minimumBalance = amount;
}

// Get minimum balance
double checkingAccount::getMinBalance() const {
    return minimumBalance;
}

// Set service charges
void checkingAccount::setServiceCharges(double amount) {
    serviceCharges = amount;
}

// Get service charges
double checkingAccount::getServiceCharges() const {
    return serviceCharges;
}

// Apply interest to the account
void checkingAccount::postInterest() {
    double interest = getAccountBalance() * (interestRate / 100.0);
    deposit(interest);
}

// Check whether balance falls below minimum
bool checkingAccount::verifyBalance() const {
    return getAccountBalance() < minimumBalance;
}

// Write a check (same as withdraw)
void checkingAccount::writeCheck(double amount) {
    withdraw(amount);
}

// Deposit override
void checkingAccount::deposit(double amount) {
    if (amount < 0) {
        std::cout << "Error: Deposit amount must be positive.\n";
        return;
    }
    bankAccount::deposit(amount);
}

// Withdraw override with minimum balance check
void checkingAccount::withdraw(double amount) {
    if (amount < 0) {
        std::cout << "Error: Withdraw amount must be positive.\n";
        return;
    }

    double current = getAccountBalance();

    if (amount > current) {
        std::cout << "Error: Insufficient funds.\n";
        return;
    }

    // Standard withdrawal
    bankAccount::withdraw(amount);

    // If balance drops below minimum, apply service charges
    if (verifyBalance()) {
        std::cout << "Balance below minimum. Applying service charge of $"
                  << serviceCharges << ".\n";
        bankAccount::withdraw(serviceCharges);
    }
}

// Print account information
void checkingAccount::print() const {
    std::cout << "=== Checking Account Information ===\n";
    bankAccount::print();
    std::cout << "Interest Rate: " << interestRate << "%\n";
    std::cout << "Minimum Balance: $" << minimumBalance << '\n';
    std::cout << "Service Charges: $" << serviceCharges << "\n";
}