#include <iostream>
#include<string>
using namespace std;

class Car {
public:
    mutable int engineHorsepower;  
    mutable int seatingCapacity;    
    mutable int noOfSpeakers;
    Car(int hp, int cap, int sp)
        : engineHorsepower(hp), seatingCapacity(cap), noOfSpeakers(sp) {}
    void modify_hp(int horsepower) const{
        engineHorsepower=horsepower;
    }
    void modify_seating(int seating) const{
        seatingCapacity=seating;
    }
    void modify_speakers(int speakers) const{
        noOfSpeakers=speakers;
    }
    void displayDetails() const{
        cout<<"Engine Horsepower: "<<engineHorsepower<<endl;
        cout<<"Seating Capacity: "<<seatingCapacity<<endl;
        cout<<"Number of Speakers: "<<noOfSpeakers<<endl;
    }
};

int main(int argc, char* argv[]) {
	
    Car myCar(stoi(argv[1]), stoi(argv[2]),stoi(argv[3]));
    myCar.displayDetails();
    cout<<"Updating car attributes"<<endl;
    myCar.modify_hp(200);
    myCar.modify_seating(7);
    myCar.modify_speakers(8);

    myCar.displayDetails();

    return 0;
}

