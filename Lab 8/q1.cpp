#include <iostream>
#include <numeric>
using namespace std;

class Fraction{
private:
    int numerator;
    int denominator; 

public:
	void reduce(){
        int gcd=std::gcd(numerator,denominator);
        numerator/=gcd;
        denominator/=gcd;
        if(denominator<0){
            numerator=-numerator;
            denominator=-denominator;
        }
    }
    Fraction(int num, int den): numerator(num), denominator(den) {
        if (denominator==0) {
            cout<<"Invalid!!!"<<endl;
            numerator=0;
            denominator=1;
	        } else {
            reduce();
        }
    }
    Fraction operator+(const Fraction& frac)const{
        return Fraction(numerator*frac.denominator+frac.numerator*denominator,denominator*frac.denominator);
    }
    Fraction operator-(const Fraction& frac)const{
        return Fraction(numerator*frac.denominator-frac.numerator*denominator,denominator*frac.denominator);
    }
    Fraction operator*(const Fraction& frac)const{
        return Fraction(numerator*frac.numerator,denominator*frac.denominator);
    }
    Fraction operator/(const Fraction& frac)const{
        if (frac.numerator==0) {
            cout<<"Invalid division!!"<<endl;
            return Fraction(0,1); 
        }
        return Fraction(numerator*frac.denominator, denominator*frac.numerator);
    }
    bool operator==(const Fraction& frac) const{
        return numerator==frac.numerator && denominator==frac.denominator;
    }
    bool operator!=(const Fraction& frac) const{
        return !(*this==frac);
    }
    bool operator<(const Fraction& frac) const{
        return numerator*frac.denominator<frac.numerator*denominator;
    }
    bool operator>(const Fraction& frac) const{
        return frac<*this;
    }
    bool operator<=(const Fraction& frac) const{
        return !(*this > frac);
    }
    bool operator>=(const Fraction& frac) const{
        return !(*this<frac);
    }
    friend ostream& operator<<(ostream& os, const Fraction& f){
        os<<f.numerator<<"/"<<f.denominator;
        return os;
    }
    friend istream& operator>>(istream& is, Fraction& f){
        char slash;
        is>>f.numerator>>slash>>f.denominator;
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(2, 4), f2(3, 6);
    cout<<(f1+f2)<<endl;
    return 0;
}

