#include "Employee(q4a).h"
#include <cstdlib>

using namespace std;

void Employee::RaiseSalary(double percent){
    monthlySalary+=monthlySalary*(percent/100);
}

void Employee::DisplaySalary() {
    cout<<firstName<<" "<<lastName<<"'s Yearly Salary: $"<<(monthlySalary*12)<<endl;
}

int main(int argc, char* argv[]){
    if (argc!=7){
        cout<<"Invalid Input\n";
        return 1;
    }

    Employee emp1,emp2;

    emp1.firstName=argv[1];
    emp1.lastName=argv[2];
    emp1.monthlySalary=stof(argv[3]);
    emp2.firstName=argv[4];
    emp2.lastName=argv[5];
    emp2.monthlySalary=stof(argv[6]);

    if(emp1.monthlySalary<0){
    	emp1.monthlySalary=0.0;}    	
    if(emp2.monthlySalary<0){
	 emp2.monthlySalary=0.0;}

    cout<<"Initial Salaries:\n";
    emp1.DisplaySalary();
    emp2.DisplaySalary();
    emp1.RaiseSalary(10);
    emp2.RaiseSalary(10);
    cout<<"\nAfter 10% Raise:\n";
    emp1.DisplaySalary();
    emp2.DisplaySalary();

    return 0;
}

