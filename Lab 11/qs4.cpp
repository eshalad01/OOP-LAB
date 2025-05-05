#include <iostream>
using namespace std;

template <typename T>
class Base {
protected:
    T value1;
    T value2;

public:
    Base(T v1, T v2) : value1(v1), value2(v2) {}
};

template <typename T>
class Derived : public Base<T> {
private:
    T value3;
    T value4;

public:
    Derived(T v1, T v2, T v3, T v4) : Base<T>(v1, v2), value3(v3), value4(v4) {}

    void multiplyAndPrint() {
        T baseProduct = this->value1 * this->value2;
        T derivedProduct = value3 * value4;
        cout << "Base Class Product: " << baseProduct << endl;
        cout << "Derived Class Product: " << derivedProduct << endl;
    }
};

int main() {
    Derived<int> obj(2, 3, 4, 5);
    obj.multiplyAndPrint();
    return 0;
}

