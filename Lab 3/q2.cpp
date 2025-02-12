#include<iostream>

using namespace std;
class Date{
private:
int month;
int date;
int year;

public:
void setDate(int m, int d, int y){
month=m;
date=d;
year=y;
}

void displayDate(){
cout<<"Date:"<<month<<"/"<<date<<"/"<<year<<endl;
}
};

int main(int argc, char* argv[]){
if(argc<4){
cout<<"Invalid Input"<<endl;
}
Date date;
date.setDate(stoi(argv[1]),stoi(argv[2]),stoi(argv[3]));
date.displayDate();

return 0;
}
