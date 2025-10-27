#include <iostream>
#include <string>
#include <exception>

using namespace std;

// ============================================================================
// PART 1: Custom Exception Hierarchy
// ============================================================================

// Base class for all bank-related exceptions
// Inherits from std::runtime_error (which inherits from std::exception)
class BankException : public runtime_error {
protected:
    string accountNumber;

public:
    BankException(const string& message, const string& acctNum)
        : runtime_error(message), accountNumber(acctNum) {}

    string getAccountNumber() const { return accountNumber; }
};

// Thrown when withdrawal exceeds balance
class InsufficientFundsException : public BankException {
private:
    double attemptedAmount;
    double currentBalance;

public:
    InsufficientFundsException(const string& acctNum, double attempted, double balance)
        : BankException("Insufficient funds for withdrawal", acctNum),
          attemptedAmount(attempted),
          currentBalance(balance) {}

    double getAttemptedAmount() const { return attemptedAmount; }
    double getCurrentBalance() const { return currentBalance; }

    // Override what() to provide detailed message
};

// Thrown for invalid amounts (negative or zero)
class InvalidAmountException : public BankException {
private:
    double invalidAmount;

public:
    InvalidAmountException(const string& acctNum, double amount)
        : BankException("Invalid transaction amount", acctNum),
          invalidAmount(amount) {}

    double getInvalidAmount() const { return invalidAmount; }
};
