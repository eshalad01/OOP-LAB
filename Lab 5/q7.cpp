#include <iostream>
#include<string>
using namespace std;

class Student {
private:
    mutable int roll_no; 

public:
    Student():roll_no(0) {}
    void setRollNo(int roll) const {
        roll_no=roll;
    }

    void displayRollNo()const {
        cout<<"Student Roll Number: "<<roll_no<<endl;
    }
};

int main(int argc, char* argv[]) {

    Student student; 
    student.setRollNo(stoi(argv[1]));

    student.displayRollNo();

    return 0;
}

