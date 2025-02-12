#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

class Employee {
public:
    string firstName;
    string lastName;
    double monthlySalary;
    void RaiseSalary(double percent);
    void DisplaySalary();
    
};

#endif
