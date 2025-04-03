#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;
public:
    Currency(double amt ,string code, string symbol,double rate=1.0): amount(amt), currencyCode(code),currencySymbol(symbol),exchangeRate(rate){}
    virtual double convertToBase(){
	return amount*exchangeRate;
	}
    virtual void displayCurrency()  {
	cout<<currencySymbol<<amount<<" ("<<currencyCode<<")"<<endl;
	}
    virtual double convertTo(Currency* targetCurrency){
	return convertToBase()/targetCurrency->exchangeRate;
	}
    void setExchangeRate(double newRate){
	if (newRate>0)exchangeRate=newRate;
	}
};

class Dollar:public Currency {
public:
    Dollar(double amt):Currency(amt,"USD","$",1.0){}
    double convertToBase()override{
	return amount;
	}
    void displayCurrency()override{
	cout<<"$"<<amount<<" (USD)"<<endl;
	}
};

class Euro:public Currency {
public:
    Euro(double amt): Currency(amt,"EUR","€",0.85){}
    double convertToBase()override{
	return amount*exchangeRate;
	}
    void displayCurrency()override{
	cout<<"€"<<amount<<" (EUR)"<<endl;
	}
};

class PakistaniRupee:public Currency {
public:
    PakistaniRupee(double amt):Currency(amt,"PKR","?",0.0061){}
    double convertToBase()override{
	return amount*exchangeRate;
	}
    void displayCurrency()override{
	cout<<"?"<<amount<<" (PKR)"<<endl;
	}
};

int main(){
    Dollar usd(100);
    Euro eur(100);
    PakistaniRupee pkr(10000);

    cout<< "USD: ";
    usd.displayCurrency();
    cout <<"EUR: ";
    eur.displayCurrency();
    cout<< "PKR: ";
    pkr.displayCurrency();

    double usdToEur=usd.convertTo(&eur);
    cout<<"100 USD is "<<usdToEur<<" EUR"<<endl;

    double eurToPkr=eur.convertTo(&pkr);
    cout<<"100 EUR is "<<eurToPkr<<" PKR"<<endl;

    double pkrToUsd=pkr.convertTo(&usd);
    cout<<"10000 PKR is "<<pkrToUsd<<" USD"<<endl;

    return 0;
}

