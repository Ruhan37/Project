#include<bits/stdc++.h>
using namespace std;

class Account;

class Transaction {
private:
    int transactionId;
    string transactionType;
    double amount;
public:
    Transaction(int id, string type, double amt) : transactionId(id), transactionType(type), amount(amt) {}
    int getTransactionId() const { return transactionId; }
    string getTransactionType() const { return transactionType; }
    double getAmount() const { return amount; }
};

class Bank {
private:
    double balance;
public:
    Bank() : balance(0.0) {}
    double getBalance() const { return balance; }
    void deposit(double amount) { balance += amount; }
    bool withdraw(double amount);
    friend void transferMoney(Account& from, Account& to, double amount);
};

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;
    int transactionCounter;
public:
    Account(string num, string name) : accountNumber(num), accountHolderName(name), balance(0.0) {}
    string getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }
    void setBalance(double amt) { balance = amt; }
    friend class ATM;
    friend void transferMoney(Account& from, Account& to, double amount);
};

class ATM {
private:
    Bank bank;
    Account account1;
    Account account2;
    int transactionCounter;
public:
    ATM(string accountNumber1, string accountHolderName1, string accountNumber2, string accountHolderName2) :
            account1(accountNumber1, accountHolderName1),
            account2(accountNumber2, accountHolderName2),
            transactionCounter(0) {}
    void showMenu();
    void deposit(double amount);
    void withdraw(double amount);
    void displayTransactions() const;
    void displayUserDetails() const;
};

bool Bank::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void transferMoney(Account& from, Account& to, double amount) {
    if (amount <= from.balance) {
        from.balance -= amount;
        to.balance += amount;
        Transaction t1(++from.transactionCounter, "Transfer (To " + to.accountHolderName + ")", amount);
        Transaction t2(++to.transactionCounter, "Transfer (From " + from.accountHolderName + ")", amount);
        cout << "Transfer successful. Transferred amount: " << amount << endl;
    } else {
        cout << "Insufficient balance. Transfer failed." << endl;
    }
}

void ATM::showMenu() {
    int option;
    double amount;
    do {
        cout << "---- ATM Menu ----" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Transfer Money" << endl;
        cout << "4. Display User Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                deposit(amount);
                break;
            case 2:
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                withdraw(amount);
                break;
            case 3: {
                string recipientAccount;
                cout << "Enter the recipient's account number: ";
                cin >> recipientAccount;
                Account* toAccount = nullptr;
                if (recipientAccount == account1.getAccountNumber()) {
                    toAccount = &account1;
                } else if (recipientAccount == account2.getAccountNumber()) {
                    toAccount = &account2;
                }
                if (toAccount) {
                    cout << "Enter the amount to transfer: ";
                    cin >> amount;
                    transferMoney(account1, *toAccount, amount);
                } else {
                    cout << "Recipient account not found." << endl;
                }
                break;
            }
            case 4:
                displayUserDetails();
                break;
            case 5:
                cout << "Exiting ATM. Thank you!" << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 5);
}

void ATM::deposit(double amount) {
    bank.deposit(amount);
    account1.setBalance(account1.getBalance() + amount);
    Transaction t(++transactionCounter, "Deposit", amount);
    cout << "Deposit successful. Current balance: " << account1.getBalance() << endl;
}

void ATM::withdraw(double amount) {
    if (bank.withdraw(amount)) {
        account1.setBalance(account1.getBalance() - amount);
        Transaction t(++transactionCounter, "Withdraw", amount);
        cout << "Withdrawal successful. Current balance: " << account1.getBalance() << endl;
    } else {
        cout << "Insufficient balance. Withdrawal failed." << endl;
    }
}

void ATM::displayTransactions() const {
    cout << "---- Transaction History ----" << endl;
    cout << "Transaction ID | Transaction Type | Amount" << endl;
}

void ATM::displayUserDetails() const {
    cout << "---- User 1 Details ----" << endl;
    cout << "Account Number: " << account1.getAccountNumber() << endl;
    cout << "Account Holder Name: " << account1.getAccountHolderName() << endl;
    cout << "Current Balance: " << account1.getBalance() << endl;
    cout << "---- User 2 Details ----" << endl;
    cout << "Account Number: " << account2.getAccountNumber() << endl;
    cout << "Account Holder Name: " << account2.getAccountHolderName() << endl;
    cout << "Current Balance: " << account2.getBalance() << endl;
}

int main() {
    ATM atm("2107025", "Ruhan", "2107063", "Rahulmehedi");
    atm.showMenu();
    return 0;
}
