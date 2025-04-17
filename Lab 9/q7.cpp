#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    double salary;
public:
    virtual void getData() = 0;
    virtual void displayData() = 0;
    virtual double calculateBonus() = 0;
};

class Admin : virtual public Person {
public:
    void getData() override {
        cout << "Enter Admin Name: ";
        cin >> name;
        cout << "Enter Admin Salary: ";
        cin >> salary;
    }

    void displayData() override {
        cout << "Admin Name: " << name << endl;
        cout << "Admin Salary: " << salary << endl;
    }

    double calculateBonus() override {
        return salary * 0.10; 
    }
};
class Account : virtual public Person {
public:
    void getData() override {
        cout << "Enter Account Name: ";
        cin >> name;
        cout << "Enter Account Salary: ";
        cin >> salary;
    }

    void displayData() override {
        cout << "Account Name: " << name << endl;
        cout << "Account Salary: " << salary << endl;
    }

    double calculateBonus() override {
        return salary * 0.15; 
    }
};
class Master : public Admin, public Account {
public:
    void getData() override {
        Admin::getData(); 
        Account::getData(); 
    }

    void displayData() override {
        Admin::displayData();  
        Account::displayData(); 
    }

    double calculateBonus() override {
        return Admin::calculateBonus() + Account::calculateBonus();
    }
};

int main() {
    Person* emp; 
    Master master;
    emp = &master;

    emp->getData();
    emp->displayData();
    cout << "Total Bonus: " << emp->calculateBonus() << endl;

    return 0;
}

