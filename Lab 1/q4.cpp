#include <iostream>
#include <string>
#include<cstdio>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc!=2) {
        cout<<"Invalid Inputs."<<endl;
        return 1;
    }
    
   float weight_kgs=stof(argv[1]);

   float weight_pounds=weight_kgs*2.2;
   printf("Weight in kgs: %.2f \nWeight in pounds: %.2f", weight_kgs,weight_pounds);


    return 0;
}

