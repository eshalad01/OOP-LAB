#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	
    if(argc<2){ 
	cout<<"Invalid Inputs. Please provide numbers as arguments."<<endl;
        return 1;
    }
    int size=argc-1;    
    float arr[size];
    float *ptr=arr;
    float sum=0;
    for (int i=0;i<size;i++) {
        *(ptr+i)=stof(argv[i+1]);
    }
for(int i=0;i<size;i++){
	sum+=*(ptr+i);
}
    cout<<"Sum: "<<sum<<endl;

    return 0;
}

