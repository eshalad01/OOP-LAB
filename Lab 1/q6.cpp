#include <iostream>
#include <string>
#include<cstdio>
using namespace std;

int main(int argc, char* argv[]) {
	 if(argc!=7){
   	cout<<"Invalid Inputs"<<endl;
   	return 1;
   }

   string name=argv[1];
   float arr[5];
    for (int i=0;i<5;i++) {
        arr[i]=stof(argv[i+2]);
    }
   printf("Student Name: %s \n",name.c_str());
   printf("Test scores: ");
   for(int i=0;i<5;i++){   	
   printf("%.2f ", arr[i]);
   }
   float average=0;
   float sum=0;
   for(int i=0;i<5;i++){   	
   sum+=arr[i];
   }
   average=sum/5;
   printf("\nAverage test score: %.2f", average);


    return 0;
}
