#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    string getModel() const {
        return model;
    }

    double getPrice() const {
        return price;
    }

    void setModel(string m) {
        model = m;
    }

    virtual void setPrice(double p) = 0;

    virtual void displayInfo() const = 0;
};

class Color : public Car {
private:
    string color;

public:
    Color(string m, double p, string c) : Car(m, p), color(c) {}

    void setPrice(double p) override {
        price = p; 
    }

    void displayInfo() const override {
        cout << "Model: " << model << ", Price: $" << price << ", Color: " << color << endl;
    }
};

class Company : public Car {
private:
    string companyName;

public:
    Company(string m, double p, string cName) : Car(m, p), companyName(cName) {}

    void setPrice(double p) override {
        price = p * 2;
    }

    void displayInfo() const override {
        cout << "Model: " << model << ", Price: $" << price << ", Company: " << companyName << endl;
    }
};

int main() {
    Color car1("Corolla", 1400000, "White");
    car1.setPrice(21000);
    car1.displayInfo();

    Company car2("Brv", 400000, "Honda");
    car2.setPrice(28000);
    car2.displayInfo();

    return 0;
}

