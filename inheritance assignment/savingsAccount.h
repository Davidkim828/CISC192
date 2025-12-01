#pragma once
#include "bankAccount.h"

class savingsAccount : public bankAccount {
private:
    double interestRate = 0.0;       // Annual interest rate (in %)

public:
    // Constructors
    savingsAccount();
    savingsAccount(int accountNumber, double balance, double interestRate);

    // Setters and getters
    void setInterestRate(double rate);
    double getInterestRate() const;

    // Add interest to the account
    void postInterest();

    // Withdraw override for savings rules
    void withdraw(double amount) override;

    // Display account information
    void print() const override;
};