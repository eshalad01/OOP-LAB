#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account(double initialBalance){
        if(initialBalance<0){
            balance=0;
        } 
		else{
            balance=initialBalance;
            cout<<"Account balance set to: "<<balance<<endl;
        }
    }
    void credit(double amount) {
        balance+=amount;
        cout<<"Amount credited to account: "<<amount<<endl;        
    }
    void debit(double amount) {
        if (amount>balance){
            cout<<"Debit amount exceeded account balance."<<endl;
        } 
		else{
            balance-=amount;
            cout<<"Amount debited to account: "<<amount<<endl; 
        }
    }
    double getBalance() {
        return balance;
    }
};

int main(int argc, char* argv[]) {
    Account account(1000.0); 
    account.credit(500.0);
    cout<<"Current Balance: "<<account.getBalance()<<endl;
    account.debit(350.0); 
    cout<<"Current Balance: "<<account.getBalance()<<endl; 
    account.debit(150.0);
    cout<<"Current Balance: "<<account.getBalance()<<endl;

    return 0;
}

