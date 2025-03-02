#include<iostream>
#include<vector>
using namespace std;

class Car{
public:
string name;
int id;
Car(){
cout<<"Car created"<<endl;
}

Car(string n, int i): name(n), id(i)
{ cout<<"Car created"<<endl;}
~Car(){
cout<<"Car destroyed"<<endl;
}
};

class Garage{
private:
vector<Car*>cars;
public:
Garage(){
cout<<"Garage created"<<endl;
}
void parkCar( Car* car){
cars.push_back(car);
}
void listCars(){
cout<<"Cars in Garge:"<<endl;
if (cars.empty()) {
    cout<<"No cars in the garage!"<<endl;
}
for(Car* car: cars){
cout<<"ID: "<<car->id<<" Name: "<<car->name<<endl;
}
}
~Garage(){
cout<<"Garage destroyed"<<endl;
for (Car* car:cars) {
    delete car;
}
}
};

int main(int argc, char* argv[]){
    Car* car1=new Car("Lexus", 1);
    Car* car2=new Car("Ford",2);
    Car* car3=new Car("Tesla", 3);
Garage garage;
garage.parkCar(car1);
garage.parkCar(car2);
garage.parkCar(car3);

garage.listCars();
delete car1;
cout<<"After deleting car1: "<<endl;
garage.listCars();
delete car2;
delete car3;
return 0;
}