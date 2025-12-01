#pragma once
#include "bankAccount.h"

class checkingAccount : public bankAccount {
private:
    double interestRate = 0.0;       // Annual interest rate (in %)
    double minimumBalance = 0.0;     // Required minimum balance
    double serviceCharges = 0.0;     // Service charge if minimum balance is not met

public:
    // Constructors
    checkingAccount();
    checkingAccount(int accountNumber, double balance,
                    double interestRate, double minimumBalance,
                    double serviceCharges);

    // Setters and getters
    void setInterestRate(double rate);
    double getInterestRate() const;

    void setMinBalance(double amount);
    double getMinBalance() const;

    void setServiceCharges(double amount);
    double getServiceCharges() const;

    // Add interest to the balance
    void postInterest();

    // Check whether the balance is below the minimum
    bool verifyBalance() const;

    // Write a check (withdraw)
    void writeCheck(double amount);

    // Deposit / Withdraw overrides
    void deposit(double amount) override;
    void withdraw(double amount) override;

    // Display account information
    void print() const override;
};