#include <iostream>
#include <cstdlib>

using namespace std;

void addToArray(void* arr, int size) {
    int* intArray=static_cast<int*>(arr);
    for (int i=0;i<size;i++) {
        intArray[i]+=5;
		    }
}

int main(int argc, char* argv[]) {
    if (argc<2) {
        cout<<"Please provide integer values as command line arguments."<<endl;
        return 1;
    }

    int size=argc-1;
    int* array=new int[size];

    for(int i=0;i<size;i++) {
        array[i]=atoi(argv[i+1]);
    }

    addToArray(static_cast<void*>(array),size);

    cout<<"Modified Array: ";
    for (int i=0;i<size;i++) {
        cout<<array[i]<< " ";
    }
    cout<<endl;

    delete[] array;
    return 0;
}

