#include<iostream>
using namespace std;

class Shape{
private:
    double area;
public:
    Shape(double a):area(a){}
    double Area()const{
        return area;
    }
    Shape operator+(const Shape& other){
        return Shape(this->area+other.area);
    }
};

int main(){
    Shape shape1(10.5);
    Shape shape2(20.3);
    Shape shape3=shape1+shape2;
    cout<<"Total Area: "<<shape3.Area()<<endl;
    return 0;
}

