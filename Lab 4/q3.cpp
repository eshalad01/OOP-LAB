#include <iostream>
#include <string>

using namespace std;

class Invoice{
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string partNum, string partDesc, int qty, double price) {
        partNumber=partNum;
        partDescription=partDesc;
        
        if(qty>0){
        quantity=qty;
        }else{
        quantity=0;
        }
        if(price>0.0){
        pricePerItem=price;
        }else{
        pricePerItem=0.0;
        }
    }
    double getInvoiceAmount(){
        return quantity*pricePerItem;
    }
};

int main(int argc,char* argv[]){
    if (argc < 5){
        cout<<"Invalid Input"<<endl;
        return 1;
    }

    Invoice invoice(argv[1], argv[2], stoi(argv[3]), stod(argv[4]));
    cout<<"Invoice Amount: $"<<invoice.getInvoiceAmount()<<endl;

    return 0;
}

