#include<iostream>
using namespace std;

class Glass{
public:
int LiquidLevel;

 void Drink(int milliliters){
        if(milliliters>LiquidLevel){
            cout<<"Insufficient quantity in the glass!"<<endl;
            LiquidLevel=0;
        } 
		else{
            LiquidLevel-=milliliters;
        }
        if(LiquidLevel<100) {
            Refill();
        }
    }
void Refill(){
LiquidLevel=200;
cout<<"The glass is refilled to full"<<endl;
}

};
int main(int argc, char* argv[]){
Glass glass;
glass.LiquidLevel=200;
    int drinkAmount;
while(true){
cout<<"Enter amount of liquid to drink or enter -1 to exit= ";
cin>>drinkAmount;
if(drinkAmount==-1){
	cout << "Exiting the program..." << endl;
return 0;
}
glass.Drink(drinkAmount);
cout<<"You drank= "<<drinkAmount <<"ml"<<endl;
cout<<"Current liquid level:"<< glass.LiquidLevel<<"ml"<<endl;
}
return 0;
}
