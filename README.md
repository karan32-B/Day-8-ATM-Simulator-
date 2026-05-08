ATM Simulator (Robust Version)
This is a C++ console application that simulates a real-life ATM system. It focuses on object-oriented programming (OOP) and professional error handling to ensure all transactions are secure and logical.

Project Features
Secure Login: Users must enter a 4-digit PIN to access their account.

Account Lockout: As a security measure, the system locks the account after 3 wrong PIN attempts.

Balance Management: Users can check their current balance at any time.

Safe Deposits: The system allows users to add funds but blocks negative or zero-value deposits.

Smart Withdrawals: The system prevents users from withdrawing more money than they actually have.

Error Messaging: Uses advanced "Try-Catch" blocks to show clear error messages instead of crashing.

Core Concepts Used
Object-Oriented Programming (OOP): All account data is safely stored within a class.

Exception Handling: Uses the std::except library to handle invalid inputs gracefully.

State Validation: The program constantly checks the "state" of the account (like whether it is locked or has enough funds).

How to Run the Program
Copy the code into a file named main.cpp.

Open your terminal or command prompt.

Compile the code using: g++ main.cpp -o ATM.

Run the program using: ./ATM (or ATM.exe on Windows).

Use the default PIN 1234 to log in.
