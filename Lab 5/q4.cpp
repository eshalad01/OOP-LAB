#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Blend{
	string fruits[5]={"Apple","Mango","Orange","Lychee","Peach"};
public:
	void select_fruits(){
	cout<<"Select fruits and enter the respective number"<<endl;
	cout<<"1.Apple"<<endl<<"2.Mango"<<endl<<"3.Orange"<<endl<<"4.Lychee"<<endl<<"5.Peach"<<endl;
	int choice;
	cin>>choice;
	switch(choice){
		case 1:
			fruit_selected("Apple");
			break;
		case 2:
			fruit_selected("Mango");
			break;
		case 3:
			fruit_selected("Orange");
			break;
		case 4:
		    fruit_selected("Lychee");
			break;
		case 5:
			fruit_selected("Peach");
			break;
		default:
			cout<<"Invalid choice"<<endl;
		return;
		
	}
	}
	void fruit_selected(string fruit){
		cout<<fruit<<" selected!!"<<endl;
	}
    void blend_juice(){
        cout<<"Blending the juice...."<<endl;
        for(int i=0;i<5;i++){
            cout<<"Blending..."<<endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout<<"The juice is blended!"<<endl;
    }
};
class Grind{
public:
    void grind_juice() {
        cout<<"Grinding the juice..."<<endl;
        for(int i=0;i<5;i++){
            cout<<"Grinding..."<<endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
         cout<<"The juice is grinded!"<<endl;
     }
        
};

class JuiceMaker{
private:
    Blend blender;
    Grind grinder;

public:
    void makeJuice(){
    	blender.select_fruits();
        blender.blend_juice();
        grinder.grind_juice();
    }
};

int main(int argc, char* argv[]) {
    JuiceMaker juiceMaker;
    juiceMaker.makeJuice();
    return 0;
}

