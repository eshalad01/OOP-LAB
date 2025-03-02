#include<iostream>
using namespace std;
class Engine{
private:
bool isRunning;
public:
Engine(){
isRunning=false;
cout<<"Engine created"<<endl;
}
void start(){
isRunning=true;
cout<<"Engine started"<<endl;
}
void stop(){
isRunning=false;
cout<<"Engine stopped"<<endl;
}
~Engine(){
cout<<"Engine destroyed"<<endl;
}
};
class Car{
private:
Engine engine;
public:
Car(){
cout<<"Car created"<<endl;
}
void startCar(){
engine.start();
}
void stopCar(){
engine.stop();
}
~Car(){
cout<<"Car destroyed"<<endl;
}
};

int main(int argc, char* argv[]){
Car car;
car.startCar();
car.stopCar();


return 0;
}