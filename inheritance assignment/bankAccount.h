#pragma once
#include <iostream>

class bankAccount {
private:
    int accountNumber = 0;       // Stores the account number
    double balance = 0.0;        // Stores the current balance

public:
    // Default constructor
    bankAccount();

    // Parameterized constructor
    bankAccount(int accountNumber, double balance);

    // Setters and getters
    void setAccountNumber(int accountNumber);
    int getAccountNumber() const;

    double getAccountBalance() const;

    // Deposit and withdraw functions
    virtual void deposit(double amount);
    virtual void withdraw(double amount);   // Virtual for polymorphic behavior

    // Print account information
    virtual void print() const;
};