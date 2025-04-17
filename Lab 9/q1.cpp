#include <iostream>
#include <string>

using namespace std;

class Wallet {
private:
    float balance;
    float DepLim_daily;
    float WithdrawalLim_daily;
    float DepositTotal;
    float WithdrawalTotal;

public:
    Wallet(float depositLimit, float withdrawalLimit) 
        : balance(0), DepLim_daily(depositLimit), WithdrawalLim_daily(withdrawalLimit), 
          DepositTotal(0), WithdrawalTotal(0) {}

    void deposit(float amount) {
        if (amount < 0) {
		cout<<"Invalid amount!!"<<endl;
		return;}
        if (DepositTotal + amount > DepLim_daily)
		{cout<<"Daily limit reached"<<endl;	
		return;	}
        balance += amount;
        DepositTotal += amount;
        cout<<"Amount deposited"<<endl;
        return;
        
    }

    void withdraw(float amount) {
        if (amount < 0 || amount > balance) {
        	cout<<"Invalid amount"<<endl;
        	return;
		}
        if (WithdrawalTotal + amount > WithdrawalLim_daily){
        	cout<<"Daily limit reached"<<endl;
        	return;
		}
        balance -= amount;
        WithdrawalTotal += amount;
        cout<<"Amount withdrawn"<<endl;
        return;
    }

    double getBalance(){
        return balance;
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string name, float depositLimit, float withdrawalLimit) 
        : userID(id), name(name), wallet(depositLimit, withdrawalLimit) {}

    void deposit(float amount) {
         wallet.deposit(amount);
    }

    void withdraw(float amount) {
         wallet.withdraw(amount);
    }

    float checkBalance()  {
        float x=wallet.getBalance();
        return x;
    }
    string getname(){
    	return name;
	}
};

int main() {
    User user1("001", "Anas", 1200, 200);
    User user2("002", "Saba", 2000, 500);

    user1.deposit(500);
    user1.withdraw(200);
    cout << "Anas's balance: " << user1.checkBalance() << endl;

    user2.deposit(2000); 
    user2.withdraw(800);
    cout << "Saba's balance: " << user2.checkBalance() << endl;

    return 0;
}

