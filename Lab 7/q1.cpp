#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountHolderName, accountNumber, accountType;
    double balance;
public:
    Account(string name, string number, string type): accountHolderName(name), accountNumber(number), balance(0.0), accountType(type) {}
    void deposit(double amount) {
        if(amount<=0) {cout << "Deposit amount must be positive." << endl; return;}
        balance+=amount;
        cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
    }
    virtual void withdraw(double amount) {
        if(amount<=0) {cout << "Withdrawal amount must be positive." << endl; return;}
        if(amount>balance) {cout << "Insufficient funds!" << endl;} 
        else {balance-=amount; cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;}
    }
    virtual void calculateInterest() {cout << "Interest calculation not applicable for this account type." << endl;}
    void getAccountInfo() {
        cout << "Account Holder: " << accountHolderName << ", Account Number: " << accountNumber << ", Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    bool isCompound;
public:
    SavingsAccount(string name, string number, double rate, bool compound): Account(name, number, "Savings"), interestRate(rate), isCompound(compound) {}
    void calculateInterest() override {
        double interest=0;
        if(isCompound) interest=balance*(1+interestRate/100)-balance;
        else interest=balance*(interestRate/100);
        cout << (isCompound?"Compound":"Simple") << " Interest earned: $" << interest << endl;
    }
};

class CheckingAccount : public Account {
private:
    double minimumBalance;
public:
    CheckingAccount(string name, string number, double minBalance): Account(name, number, "Checking"), minimumBalance(minBalance) {}
    void withdraw(double amount) override {
        if(amount<=0) {cout << "Withdrawal amount must be positive." << endl;
		 return;}
        if(balance-amount<minimumBalance) {
		cout << "Overdraft not allowed! Minimum balance of $" << minimumBalance << " must be maintained." << endl;
		}
        else {
		balance-=amount; cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
		}
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;
public:
    FixedDepositAccount(string name, string number, double rate, string maturity): Account(name, number, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}
    void calculateInterest() override {
        double interest=balance*(fixedInterestRate/100);
        cout << "Fixed Deposit Interest earned: $" << interest << " until " << maturityDate << endl;
    }
};

int main() {
    SavingsAccount savings("Saba", "A12345", 5.0, true);
    savings.deposit(1000);
    savings.calculateInterest();
    savings.getAccountInfo();
    CheckingAccount checking("Saba", "B12345", 100.0);
    checking.deposit(500);
    checking.withdraw(450);
    checking.withdraw(500);
    checking.getAccountInfo();
    FixedDepositAccount fixedDeposit("Aliza", "C12345", 7.0, "2026-12-31");
    fixedDeposit.deposit(2000);
    fixedDeposit.calculateInterest();
    fixedDeposit.getAccountInfo();
    return 0;
}

