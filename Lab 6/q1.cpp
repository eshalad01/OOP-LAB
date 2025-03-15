#include <iostream>
using namespace std;

class BankAccount{
protected:
    string acc_no;
    float balance;

public:
    BankAccount(string a, float b):acc_no(a), balance(b) {}

    void deposit(float amount) {
        if (amount>0) {
            balance+=amount;
            cout<<"Amount $" <<amount<<" deposited. New Balance: $"<<balance<<endl;
        } else {
            cout<<"Invalid deposit amount!"<<endl;
        }
    }

    void withdraw(float amount) {
        if (amount>0 && amount<=balance) {
            balance-= amount;
            cout<<"Amount $"<<amount<<" withdrawn. New Balance: $"<<balance<<endl;
        } else {
            cout<<"Invalid withdrawal amount or insufficient balance!"<<endl;
        }
    }

    float getBalance() {
        return balance;
    }
};

class SavingsAccount : public BankAccount {
private:
    float interest_rate;

public:
    SavingsAccount(string a, float b, float r):BankAccount(a, b), interest_rate(r) {}

    void applyMonthlyInterest() {
        float interest=(balance*interest_rate)/1200;
        balance+=interest;
        cout<<"Interest applied: $"<<interest<<". New Balance: $"<<balance<<endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    float overdraft_limit;

public:
    CheckingAccount(string a, float b, float l) : BankAccount(a, b), overdraft_limit(l) {}

    void applyOverdraft(float amount) {
        if (amount>0 && (balance-amount)>=-overdraft_limit) {
            balance-=amount;
            cout<<"Overdraft of $"<<amount<<" successful! New Balance: $"<<balance<<endl;
        } else {
            cout<<"Overdraft limit reached!"<<endl;
        }
    }
};

class BusinessAccount : public BankAccount {
private:
    float tax_rate;

public:
    BusinessAccount(string a, float b, float r) : BankAccount(a, b), tax_rate(r) {}

    void applyTax(float depositAmount) {
        float tax=(tax_rate/100)*depositAmount;
        balance+=(depositAmount-tax);
        cout<<"Tax applied: $"<<tax<<". Amount after tax: $" <<depositAmount-tax<<endl;
    }
};
class Customer {
protected:
    string name;
    BankAccount* account;

public:
    Customer(string n, BankAccount* acc):name(n), account(acc) {}

    void deposit(float amount) {
        account->deposit(amount);
    }

    void withdraw(float amount) {
        account->withdraw(amount);
    }
};

class Employee {
protected:
    string name;

public:
    Employee(string n):name(n) {}

    virtual void accessBankAccount(BankAccount* acc) {
        cout<<"Employee accessing bank account." << endl;
    }
};

class Teller : public Employee {
public:
    Teller(string n):Employee(n) {}

    void freezeAccount(BankAccount* acc) {
        cout<<"Account has been frozen by Teller: "<<name<<endl;
    }
};

class Manager : public Employee {
public:
    Manager(string n) :Employee(n) {}

    void overrideLimit(BankAccount* acc) {
        cout<<"Manager " <<name <<" has overridden account limits." <<endl;
    }
};

int main() {
    SavingsAccount savings("12345", 1000, 5);
    CheckingAccount checking("67890", 500, 200); 
    BusinessAccount business("54321", 2000, 10);

    Customer cust("Anas", &savings);
    Teller teller("Burhan");
    Manager mgr("Faizan");
    cust.deposit(200);
    cust.withdraw(50);
    savings.applyMonthlyInterest();

    teller.freezeAccount(&checking);
    mgr.overrideLimit(&business);

    return 0;
}

