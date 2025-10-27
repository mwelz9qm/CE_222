## Exception Hierarchy

Our custom exceptions inherit from the C++ standard library to ensure compatibility and best practices:

```
std::exception
    └── std::runtime_error
            └── BankException (base class for all bank errors)
                    ├── InsufficientFundsException
                    ├── InvalidAmountException
                    ├── InvalidAccountException
                    └── AccountNotEmptyException
```

### Why This Hierarchy?

1. **Inherits from `runtime_error`**: These are runtime conditions (not programming bugs)
2. **Common base class (`BankException`)**: Allows catching all bank-related errors together
3. **Specific exception types**: Each error type carries relevant context data

## Exception Classes

### `BankException` (Base Class)

**Purpose**: Base class for all bank-related exceptions

**Data Members**:
- `accountNumber`: The account involved in the error

**Methods**:
- `getAccountNumber()`: Returns the account number

**Why it exists**: Provides common functionality for all bank exceptions and allows polymorphic catching.

---

### `InsufficientFundsException`

**Purpose**: Thrown when a withdrawal exceeds the available balance

**Data Members**:
- `attemptedAmount`: The amount the user tried to withdraw
- `currentBalance`: The actual balance available

**Methods**:
- `getAttemptedAmount()`: Returns the attempted withdrawal amount
- `getCurrentBalance()`: Returns the current balance
- `what()`: Overridden to provide detailed error message

**Example**:
```cpp
throw InsufficientFundsException("12345678", 150.0, 100.0);
// "Insufficient funds (Attempted: $150, Balance: $100)"
```

---

### `InvalidAmountException`

**Purpose**: Thrown when an amount is invalid (negative or zero)

**Data Members**:
- `invalidAmount`: The invalid amount that was provided

**Methods**:
- `getInvalidAmount()`: Returns the invalid amount

**Example**:
```cpp
throw InvalidAmountException("12345678", -50.0);
// "Invalid transaction amount"
```

---

### `InvalidAccountException`

**Purpose**: Thrown when an account number doesn't meet format requirements (must be exactly 8 digits)

**Methods**:
- Inherits `getAccountNumber()` from `BankException`

**Example**:
```cpp
throw InvalidAccountException("ABC123");
// "Invalid account number format"
```

---

### `AccountNotEmptyException`

**Purpose**: Thrown when attempting to close an account that still has a balance

**Data Members**:
- `remainingBalance`: The balance that must be withdrawn first

**Methods**:
- `getRemainingBalance()`: Returns the remaining balance

**Example**:
```cpp
throw AccountNotEmptyException("12345678", 750.0);
// "Cannot close account with remaining balance"
```

## The Six Examples

### Example 1: Normal Operations (Happy Path)

**What it demonstrates**: Successful operations with no exceptions

**Code Flow**:
1. Create account with valid data
2. Deposit money
3. Withdraw money
4. Check balance

**Key Learning**: Not everything throws exceptions! Normal operations should work smoothly.

---

### Example 2: Invalid Account Number

**What it demonstrates**: Constructor validation and exception throwing

**Error Trigger**: Creating account with "ABC123" (not 8 digits)

**Exception Thrown**: `InvalidAccountException`

**Catch Strategy**: 
- Specific catch for `InvalidAccountException`
- Fallback catch for any `BankException`

**Key Learning**: 
- Constructors can throw exceptions
- This prevents creating invalid objects
- Catch order matters (specific before general)

---

### Example 3: Insufficient Funds

**What it demonstrates**: Rich exception data and custom `what()` implementation

**Error Trigger**: Withdrawing $150 from account with $100 balance

**Exception Thrown**: `InsufficientFundsException`

**What We Access**:
- `what()`: Gets formatted error message
- `getAttemptedAmount()`: Gets $150
- `getCurrentBalance()`: Gets $100

**Key Learning**: Custom exceptions can carry detailed context data beyond just an error message.

---

### Example 4: Invalid Amount

**What it demonstrates**: Method-level validation

**Error Trigger**: Attempting to deposit -$50

**Exception Thrown**: `InvalidAmountException`

**Key Learning**: Validation can happen in methods, not just constructors.

---

### Example 5: Cannot Close Non-Empty Account

**What it demonstrates**: Business rule enforcement through exceptions

**Error Trigger**: Trying to close account with $750 balance

**Exception Thrown**: `AccountNotEmptyException`

**What We Learn**: We can suggest corrective action ("Please withdraw all funds")

**Key Learning**: Exceptions enforce business rules and guide users toward correct usage.

---

### Example 6: Generic Exception Handling

**What it demonstrates**: Polymorphic exception catching

**Error Trigger**: Withdrawing $350 from account with $300 balance

**Catch Strategy**: Using `catch (const exception& e)` to catch ANY standard exception

**Key Learning**: 
- Because our exceptions inherit from `std::exception`, they work with generic handlers
- This is why inheriting from standard exceptions matters
- Generic catching is useful for logging/cleanup while more specific catches handle errors

## Catch Order Matters!

When catching exceptions, always order from **most specific to most general**:

```cpp
try {
    // code
} 
catch (const InsufficientFundsException& e) {  // Most specific
    // Handle insufficient funds
}
catch (const BankException& e) {  // Medium specificity
    // Handle any bank error
}
catch (const runtime_error& e) {  // Less specific
    // Handle any runtime error
}
catch (const exception& e) {  // Most general
    // Catch-all for any standard exception
}
catch (...) {  // Absolute catch-all
    // Catches ANYTHING (even non-standard exceptions)
}
```

**Why?** The first matching catch block is executed. If you put the general catch first, specific ones will never be reached!

## Compiling and Running

### Linux/Mac
```bash
g++ -std=c++11 bank_exceptions.cpp -o bank
./bank
```

### Windows (MinGW)
```bash
g++ -std=c++11 bank_exceptions.cpp -o bank.exe
bank.exe
```

## Key Concepts 

### 1. Exception Class Design
- Inheriting from standard exceptions
- Storing context data in exceptions
- Overriding `what()` for custom messages

### 2. The `const char* what() const noexcept override`
- `const char*`: Return type (C-string)
- First `const`: The method doesn't modify the object
- `noexcept`: Promises not to throw (important for exception handlers!)
- `override`: Explicit indication we're overriding a base class method

### 3. Constructor Exception Safety
- Constructors have no return type, so exceptions are the ONLY way to signal failure
- If constructor throws, object is never created (no half-constructed objects)
- Memory is automatically cleaned up

### 4. RAII and Exceptions
- When exception is thrown, stack unwinding occurs
- All local objects are destroyed in reverse order of construction
- Destructors are called automatically

## Practice Exercises

Once you understand the examples, try these exercises:

### Exercise 1: Daily Limit Exception
Create a `DailyLimitExceededException` that:
- Tracks daily withdrawal total
- Prevents withdrawals over $1,000 per day
- Stores: attempted amount, already withdrawn today, daily limit

### Exercise 2: Transfer Between Accounts
Create a `transfer()` method that:
- Withdraws from one account
- Deposits to another account
- Can throw multiple exception types
- Handles partial failure (what if withdrawal succeeds but deposit fails?)

### Exercise 3: Frozen Account
Add account freezing functionality:
- Create `FrozenAccountException`
- Add `freeze()` and `unfreeze()` methods
- Throw exception when operations attempted on frozen account

### Exercise 4: Better what() Messages
Override `what()` in other exception classes to provide formatted messages like `InsufficientFundsException` does.

### Exercise 5: Exception Logging
Create a logging system that:
- Catches all exceptions
- Logs to file with timestamp
- Re-throws the exception

## Additional Resources

- [C++ Standard Exceptions](https://en.cppreference.com/w/cpp/error/exception)
- [Exception Safety Guarantees](https://en.cppreference.com/w/cpp/language/exceptions#Exception_safety)
- [When to Use Exceptions](https://isocpp.org/wiki/faq/exceptions)

## Common Pitfalls to Avoid

❌ **Don't catch by value**
```cpp
catch (BankException e)  // Makes a copy! Slicing can occur
```

✅ **Do catch by const reference**
```cpp
catch (const BankException& e)  // No copy, preserves polymorphism
```

---

❌ **Don't use exceptions for control flow**
```cpp
// BAD: Using exceptions for normal logic
if (accountExists(id)) {
    throw AccountExistsException();
}
```

✅ **Do use exceptions for exceptional cases**
```cpp
// GOOD: Exceptions for unexpected problems
if (fileCorrupted) {
    throw DataCorruptionException();
}
```

---

❌ **Don't let destructors throw**
```cpp
~BankAccount() {
    throw SomeException();  // NEVER do this!
}
```

✅ **Do make destructors noexcept**
```cpp
~BankAccount() noexcept {
    // Clean up safely
}
```

---

