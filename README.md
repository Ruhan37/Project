# 🏦 ATM Management System (C++ OOP Project)

**Developer:** Ruhan Ahsan Sarnav  
**Department:** Computer Science and Engineering (CSE)  
**Institution:** Khulna University of Engineering and Technology (KUET)  

---

## 📖 Project Overview
This is a **console-based ATM Management System** implemented in **C++ using Object-Oriented Programming (OOP)**.  
It simulates real-world ATM functionalities including deposits, withdrawals, fund transfers, and account details display.  

The project demonstrates core OOP concepts such as **classes, objects, encapsulation, constructors, and friend functions**.

---

## ✨ Key Features
- 💰 **Deposit:** Add money to an account.  
- 🏦 **Withdraw:** Withdraw money with balance validation.  
- 🔄 **Transfer Money:** Transfer funds between two accounts.  
- 📄 **User Details:** Display account information for all users.  
- 📊 **Transaction Tracking:** Track transactions using a class-based design.  

---

## 💡 Core Concepts Used
- Classes and Objects  
- Encapsulation & Data Hiding  
- Friend Functions and Friend Classes  
- Constructor Initialization  
- Composition (ATM contains Bank and Account objects)  
- Menu-driven Program Flow  

---

## 🛠 Implemented Classes
1. **Transaction** – Stores transaction details (ID, type, amount).  
2. **Bank** – Manages bank-level balance and withdrawals.  
3. **Account** – Stores account number, holder name, and balance.  
4. **ATM** – Integrates all components and provides a user interface.  

---

## 🚀 How to Run
1. Open the project in a C++ compiler (e.g., Code::Blocks, Dev-C++, VS Code).  
2. Compile the code:  
   ```bash
   g++ atm.cpp -o atm




## Run the executable:
 ```bash
   ./atm
```

## Follow the on-screen menu to perform transactions.

## ---- ATM Menu ----
1. Deposit
2. Withdraw
3. Transfer Money
4. Display User Details
5. Exit
Choose an option: 1
Enter the amount to deposit: 5000
Deposit successful. Current balance: 5000
