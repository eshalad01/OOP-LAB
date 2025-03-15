#include <iostream>
#include <string>

using namespace std;

class Vehicles {
protected:
    double price;

public:
    Vehicles(double p):price(p) {}
    virtual void display()=0;
};

class Car:public Vehicles {
protected:
    int seatingCapacity,numberOfDoors;
    string fuelType;

public:
    Car(double p,int sc,int nd,string ft):Vehicles(p),seatingCapacity(sc),numberOfDoors(nd),fuelType(ft) {}
};

class Audi:public Car {
private:
    string modelType;

public:
    Audi(double p,int sc,int nd,string ft,string mt):Car(p,sc,nd,ft),modelType(mt) {}

    void display() {
        cout<<"Audi Details:\n";
        cout<<"Price:$"<<price<<"\n";
        cout<<"Seating Capacity:"<<seatingCapacity<<"\n";
        cout<<"Number of Doors:"<<numberOfDoors<<"\n";
        cout<<"Fuel Type:"<<fuelType<<"\n";
        cout<<"Model Type:"<<modelType<<"\n";
    }
};

class Motorcycle:public Vehicles {
protected:
    int numberOfCylinders,numberOfGears,numberOfWheels;

public:
    Motorcycle(double p,int nc,int ng,int nw):Vehicles(p),numberOfCylinders(nc),numberOfGears(ng),numberOfWheels(nw) {}
};

class Yamaha:public Motorcycle {
private:
    string makeType;

public:
    Yamaha(double p,int nc,int ng,int nw,string mt):Motorcycle(p,nc,ng,nw),makeType(mt) {}

    void display() {
        cout<<"Yamaha Details:\n";
        cout<<"Price:$"<<price<<"\n";
        cout<<"Number of Cylinders:"<<numberOfCylinders<<"\n";
        cout<<"Number of Gears:"<<numberOfGears<<"\n";
        cout<<"Number of Wheels:"<<numberOfWheels<<"\n";
        cout<<"Make Type:"<<makeType<<"\n";
    }
};

int main() {
    Audi audi(50000,5,4,"Petrol","A4");
    Yamaha yamaha(15000,2,6,2,"YZF-R3");

    audi.display();
    cout<<endl;
    yamaha.display();

    return 0;
}

