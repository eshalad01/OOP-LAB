#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 21){
        cout<<"Invalid Inputs."<<endl;
        return 1;
    }

    float arr[20];
    float *ptr=arr;  
    for (int i=0;i<20;i++){
        *(ptr+i)=stof(argv[i+1]);
    }
    float *max,*smax;
    if(*ptr>*(ptr+1))
	{
    max=ptr;
    smax=ptr+1;
    }
	 else
	{
    max=ptr+1;
    smax=ptr;
    }
    for(int i=2;i<20;i++){
        if(*(ptr+i)>*max) 
		{
        smax=max;
        max=ptr+i;
        } 
		else if(*(ptr+i)>*smax && *(ptr+i)!=*max) 
		{
        smax=ptr+i;
        }
    }

    cout<<"Second Largest: "<<*smax<<endl;
    return 0;
}

