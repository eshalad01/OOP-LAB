#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0; 
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double getArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    Shape* rect = new Rectangle(5.0, 3.0);
    Shape* tri = new Triangle(4.0, 2.5);

    cout << "Area of Rectangle: " << rect->getArea() << endl;
    cout << "Area of Triangle: " << tri->getArea() << endl;

    delete rect;
    delete tri;

    return 0;
}

