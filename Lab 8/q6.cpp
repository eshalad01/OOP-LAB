#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
    int employeeID;
    string name;
    double monthlyIncome;
public:
    void getData(int id,string empName,double income){
        employeeID=id;
        name=empName;
        monthlyIncome=income;
    }
    void displayData(){
        cout<<"Employee ID: "<<employeeID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Monthly Income: $"<<monthlyIncome<<endl;
        cout<<"Bonus: $"<<calculateBonus()<<endl;
    }
    virtual double calculateBonus()const=0;
};

class Admin:public Person{
public:
    double calculateBonus()const override{
        return monthlyIncome*0.05;
    }
};

class Accounts:public Person{
public:
    double calculateBonus()const override{
        return monthlyIncome*0.05;
    }
};

int main(){
    Admin admin;
    admin.getData(1,"Alice",3000);
    admin.displayData();

    Accounts account;
    account.getData(2,"Bob",2500);
    account.displayData();

    return 0;
}

