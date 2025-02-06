#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Subject{
    string name;
};

struct Student{
    int id;
    vector<Subject> subjects; 
};

int main(int argc, char* argv[]) {
    if(argc<2) {
        cout<<"Please provide the number of students as a command line argument."<<endl;
        return 1;
    }

    int numStudents=atoi(argv[1]);
    vector<Student> students(numStudents);
    for (int i=0;i<numStudents;i++){
        students[i].id=i+1;
        students[i].subjects.push_back({"Chemistry"});
        students[i].subjects.push_back({"Calculus"});
    }
    for(const auto& student : students) {
        cout<<"Student ID: "<<student.id<<endl;
        for(const auto& subject : student.subjects) {
            cout<<" - Subject: "<< subject.name<<endl;
        }
    }

    return 0;
}

