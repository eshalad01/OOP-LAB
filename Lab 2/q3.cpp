#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[]) {
    int size=5;     
    int count=0;
    int* array=new int[size];
    for(int i=1;i<argc;i++) {
        if(count>=size) { 
            size*=2;
            int* tempArray=new int[size];
            for(int j=0;j<count;j++) {
                tempArray[j]=array[j];
            }
            delete[] array; 
            array=tempArray;
            printf("Array resized to: %d\n", size); 
        }

        array[count++]=std::stoi(argv[i]); 
    }
    printf("Final array elements: ");
    for (int i=0;i<count;i++) {  
        std::cout<<array[i] << " ";
    }
    printf("\n");
    delete[] array;

    return 0;
}

