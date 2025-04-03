#include <iostream>
#include <string>
using namespace std;

class Person{
protected:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;
public:
    Person(string n,int i, string addr,string phone,string mail): name(n),id(i),address(addr),phoneNumber(phone),email(mail){}
    virtual void displayInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Phone Number: "<<phoneNumber<<endl;
        cout<<"Email: "<<email<<endl;
    }
    void updateInfo(string n,string addr,string phone,string mail){
        name=n;
        address=addr;
        phoneNumber=phone;
        email= mail;
    }
    string getName() {
	return name;
	}
};

class Student: public Person{
private:
    string coursesEnrolled;
    float GPA;
    int enrollmentYear;
public:
    Student(string n,int i,string addr,string phone,string mail,string courses,float gpa,int year):Person(n,i,addr,phone,mail),coursesEnrolled(courses),GPA(gpa),enrollmentYear(year){}
    void displayInfo()override{
        Person::displayInfo();
        cout<<"Courses Enrolled: "<<coursesEnrolled<<endl;
        cout<<"GPA: "<<GPA<<endl;
        cout<<"Enrollment Year: "<<enrollmentYear<<endl;
    }
};

class Professor:public Person{
private:
    string department;
    string coursesTaught;
    float salary;
public:
    Professor(string n,int i, string addr,string phone,string mail ,string dept,string courses, float sal):Person(n,i,addr,phone,mail),department(dept),coursesTaught(courses),salary(sal){}
    void displayInfo()override{
        Person::displayInfo ();
        cout<<"Department: "<<department<<endl;
        cout<<"Courses Taught: "<<coursesTaught<<endl;
        cout<<"Salary: "<<salary<< endl;
    }
};

class Staff:public Person{
private:
    string department;
    string position;
    float salary;
public:
    Staff(string n,int i,string addr,string phone,string mail,string dept,string pos,float sal):Person(n,i,addr,phone,mail),department(dept),position(pos),salary(sal){}
    void displayInfo()override{
        Person::displayInfo();
        cout<<"Department: "<<department<<endl;
        cout<<"Position: "<<position<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

class Course{
private:
    int courseId;
    string courseName;
    int credits;
    Professor* instructor;
    string schedule;
public:
    Course(int id,string name,int creditHours,Professor* prof,string sched):courseId(id),courseName(name),credits(creditHours),instructor(prof),schedule(sched){}
    void registerStudent(Student& student){
        cout<<student.getName()<<" has been registered for "<<courseName<<endl;
    }
    void calculateGrades(Student& student){
        cout<<"Grades for "<<student.getName()<<" in "<<courseName<<": A"<<endl;
    }
    void displayCourseInfo(){
        cout<<"Course ID: "<<courseId<<endl;
        cout<<"Course Name: "<<courseName<<endl;
        cout<<"Credits: "<<credits<<endl;
        cout<<"Instructor: "<<instructor->getName()<<endl;
        cout<<"Schedule: "<<schedule<<endl;
    }
};

int main(){
    Student student("Bisma",1,"123 Street","123-456","bisma@email.com","Math, Science",3.5,2021);
    Professor professor("Ahsan",101,"456 University Ave","789-1234","ahsan@gmail.com","Mathematics","Algebra, Calculus",75000);
    Staff staff("Aiman",201,"789 College ","567-8912","aimann@gmail.com","Administration","Manager",50000);

    cout<<"\nStudent Info:\n";
    student.displayInfo();
    cout<<"\nProfessor Info:\n";
    professor.displayInfo();
    cout<<"\nStaff Info:\n";
    staff.displayInfo();

    Course course(101,"Calculus I",3,&professor,"Mon, Wed, Fri: 10:00 AM - 11:30 AM");
    cout<<"\nCourse Info:\n";
    course.displayCourseInfo();
    course.registerStudent(student);
    course.calculateGrades(student);

    return 0;
}

