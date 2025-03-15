#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
protected:
    int id;
    string name;

public:
    Employee(int id,const string& name):id(id),name(name) {}
    virtual ~Employee() {}

    virtual void displayInfo() const {
        cout<<"ID:"<<id<<", Name:"<<name<<endl;
    }
};

class IOrderTaker {
public:
    virtual void takeOrder()=0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder()=0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill()=0;
    virtual ~IBiller() {}
};

class Waiter:public Employee,public IOrderTaker {
public:
    Waiter(int id,const string& name):Employee(id,name) {}

    void takeOrder() {
        cout<<name<<" is taking an order."<<endl;
    }
};

class Chef:public Employee,public IOrderPreparer {
public:
    Chef(int id,const string& name):Employee(id,name) {}

    void prepareOrder() {
        cout<<name<<" is preparing an order."<<endl;
    }
};

class Cashier:public Employee,public IBiller {
public:
    Cashier(int id,const string& name):Employee(id,name) {}

    void generateBill() {
        cout<<name<<" is generating a bill."<<endl;
    }
};

class Manager:public Employee,public IOrderTaker,public IBiller {
public:
    Manager(int id,const string& name):Employee(id,name) {}

    void takeOrder() {
        cout<<name<<"(Manager) is taking an order."<<endl;
    }

    void generateBill() {
        cout<<name<<"(Manager) is generating a bill."<<endl;
    }
};

class Menu {
protected:
    string name;
    double price;

public:
    Menu(const string& name,double price):name(name),price(price) {}
    virtual ~Menu() {}

    virtual double getTotalCost() const=0;

    void displayItem() const {
        cout<<name<<" - $"<<price<<endl;
    }
};

class FoodMenu:public Menu {
public:
    FoodMenu(const string& name,double price):Menu(name,price) {}

    double getTotalCost() const {
        return price;
    }
};

class BeverageMenu:public Menu {
public:
    BeverageMenu(const string& name,double price):Menu(name,price) {}

    double getTotalCost() const {
        return price*1.1;
    }
};

int main() {
    Waiter waiter(1,"John");
    Chef chef(2,"Alice");
    Cashier cashier(3,"Bob");
    Manager manager(4,"Sarah");

    vector<Employee*> employees={&waiter,&chef,&cashier,&manager};

    cout<<"Employee List:\n";
    for(const auto& emp:employees) {
        emp->displayInfo();
    }

    cout<<"\nActions:\n";
    waiter.takeOrder();
    chef.prepareOrder();
    cashier.generateBill();
    manager.takeOrder();
    manager.generateBill();

    FoodMenu pizza("Pizza",12.5);
    BeverageMenu coffee("Coffee",3.0);

    cout<<"\nMenu Items:\n";
    pizza.displayItem();
    coffee.displayItem();

    cout<<"\nTotal Cost Calculation:\n";
    cout<<"Total cost of Pizza: $"<<pizza.getTotalCost()<<endl;
    cout<<"Total cost of Coffee (with tax): $"<<coffee.getTotalCost()<<endl;

    return 0;
}

