#include <iostream>
#include <stdexcept>

using namespace std;
class ArrayIndexOutOfBounds : public std::exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds";
    }
};

template <typename T>
class SafeArray {
private:
    T* arr;
    size_t size;

public:
    SafeArray(size_t s) : size(s) {
        arr = new T[size];
    }

    ~SafeArray() {
        delete[] arr;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw ArrayIndexOutOfBounds();
        }
        return arr[index];
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    SafeArray<int> myArray(5);
    
    try {
        myArray[0] = 10;
        myArray[1] = 20;
        myArray[2] = 30;
        myArray[3] = 40;
        myArray[4] = 50;
        
        cout << myArray[0] << endl;
        cout << myArray[5] << endl; 
    } catch (const ArrayIndexOutOfBounds& e) {
        cout << e.what() << endl; 
    }

    return 0;
}

