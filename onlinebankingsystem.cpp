#include <iostream>
#include <map>
#include <string>

// Account class definition
class Account {
public:
    int accountNumber;
    std::string accountHolder;
    double balance;

    // Default constructor
    Account() : accountNumber(0), accountHolder(""), balance(0.0) {}

    // Constructor
    Account(int accountNumber, std::string accountHolder, double balance = 0.0)
        : accountNumber(accountNumber), accountHolder(accountHolder), balance(balance) {}

    // Deposit funds
    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited: $" << amount << ". New balance: $" << balance << std::endl;
    }

    // Withdraw funds
    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << ". New balance: $" << balance << std::endl;
            return true;
        } else {
            std::cout << "Insufficient funds." << std::endl;
            return false;
        }
    }

    // Transfer funds to another account
    bool transfer(Account& recipient, double amount) {
        if (balance >= amount) {
            balance -= amount;
            recipient.balance += amount;
            std::cout << "Transferred: $" << amount << " to account " << recipient.accountNumber << std::endl;
            return true;
        } else {
            std::cout << "Insufficient funds." << std::endl;
            return false;
        }
    }
};

// BankingSystem class definition
class BankingSystem {
private:
    std::map<int, Account> accounts;

public:
    // Create a new account
    void createAccount(int accountNumber, std::string accountHolder) {
        if (accounts.find(accountNumber) == accounts.end()) {
            accounts[accountNumber] = Account(accountNumber, accountHolder);
            std::cout << "Account created successfully." << std::endl;
        } else {
            std::cout << "Account already exists." << std::endl;
        }
    }

    // Deposit funds into an account
    void deposit(int accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber].deposit(amount);
        } else {
            std::cout << "Account not found." << std::endl;
        }
    }

    // Withdraw funds from an account
    void withdraw(int accountNumber, double amount) {
        if (accounts.find(accountNumber) != accounts.end()) {
            accounts[accountNumber].withdraw(amount);
        } else {
            std::cout << "Account not found." << std::endl;
        }
    }

    // Transfer funds between accounts
    void transfer(int senderAccountNumber, int recipientAccountNumber, double amount) {
        if (accounts.find(senderAccountNumber) != accounts.end() && accounts.find(recipientAccountNumber) != accounts.end()) {
            accounts[senderAccountNumber].transfer(accounts[recipientAccountNumber], amount);
        } else {
            std::cout << "One or both accounts not found." << std::endl;
        }
    }

    // Display account information
    void displayAccountInfo(int accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            Account account = accounts[accountNumber];
            std::cout << "Account Number: " << account.accountNumber << std::endl;
            std::cout << "Account Holder: " << account.accountHolder << std::endl;
            std::cout << "Balance: $" << account.balance << std::endl;
        } else {
            std::cout << "Account not found." << std::endl;
        }
    }
};

int main() {
    BankingSystem bankingSystem;

    while (true) {
        std::cout << "Online Banking System" << std::endl;
        std::cout << "1. Create Account" << std::endl;
        std::cout << "2. Deposit Funds" << std::endl;
        std::cout << "3. Withdraw Funds" << std::endl;
        std::cout << "4. Transfer Funds" << std::endl;
        std::cout << "5. Display Account Info" << std::endl;
        std::cout << "6. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int accountNumber;
                std::string accountHolder;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter account holder's name: ";
                std::cin.ignore();
                std::getline(std::cin, accountHolder);
                bankingSystem.createAccount(accountNumber, accountHolder);
                break;
            }
            //case 2:
            case 2: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                bankingSystem.deposit(accountNumber, amount);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                bankingSystem.withdraw(accountNumber, amount);
                break;
            }
            case 4: {
                int senderAccountNumber, recipientAccountNumber;
                double amount;
                std::cout << "Enter sender's account number: ";
                std::cin >> senderAccountNumber;
                std::cout << "Enter recipient's account number: ";
                std::cin >> recipientAccountNumber;
                std::cout << "Enter amount to transfer: ";
                std::cin >> amount;
                bankingSystem.transfer(senderAccountNumber, recipientAccountNumber, amount);
                break;
            }
            case 5: {
                int accountNumber;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                bankingSystem.displayAccountInfo(accountNumber);
                break;
            }
            case 6:
                std::cout << "Exiting the system." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
