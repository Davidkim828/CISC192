#include <iostream>
#include "checkingAccount.h"
#include "savingsAccount.h"

int main() {
    // Create and test a checking account
    checkingAccount chk(1001, 1000.0, 2.0, 500.0, 25.0);

    std::cout << "Initial Checking Account:\n";
    chk.print();
    std::cout << "\n";

    std::cout << "Depositing $300 into checking...\n";
    chk.deposit(300.0);

    std::cout << "Writing a $600 check...\n";
    chk.writeCheck(600.0);

    std::cout << "Withdrawing $400 (should trigger service charge)...\n";
    chk.withdraw(400.0);

    std::cout << "\nPosting interest...\n";
    chk.postInterest();

    std::cout << "\nFinal Checking Account:\n";
    chk.print();
    std::cout << "\n\n";

    // Create and test a savings account
    savingsAccount sav(2001, 2000.0, 3.5);

    std::cout << "Initial Savings Account:\n";
    sav.print();
    std::cout << "\n";

    std::cout << "Depositing $500 into savings...\n";
    sav.deposit(500.0);

    std::cout << "Posting interest...\n";
    sav.postInterest();

    std::cout << "Withdrawing $700...\n";
    sav.withdraw(700.0);

    std::cout << "\nFinal Savings Account:\n";
    sav.print();
    std::cout << "\n";

    return 0;
}