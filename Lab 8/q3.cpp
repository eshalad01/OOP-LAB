#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class BigInteger {
private:
    vector<int> digits;
    bool isNegative;
    void removeLeadingZeros() {
        while(digits.size()>1&&digits.back()==0)digits.pop_back();
    }
public:
    BigInteger(const string& number) {
        isNegative=(number[0]=='-');
        for(int i=number.size()-1;i>=(isNegative?1:0);--i)digits.push_back(number[i]-'0');
        removeLeadingZeros();
    }
    BigInteger operator+(const BigInteger& other) const {
        if(this->isNegative&&!other.isNegative)return other-(-(*this));
        if(!this->isNegative&&other.isNegative)return *this-(-other);
        BigInteger result("0");
        result.isNegative=this->isNegative;
        int carry=0;
        size_t maxSize=max(this->digits.size(),other.digits.size());
        for(size_t i=0;i<maxSize||carry;++i){
            int sum=carry;
            if(i<this->digits.size())sum+=this->digits[i];
            if(i<other.digits.size())sum+=other.digits[i];
            result.digits.push_back(sum%10);
            carry=sum/10;
        }
        result.removeLeadingZeros();
        return result;
    }
    BigInteger operator-(const BigInteger& other) const {
        if(*this==other)return BigInteger("0");
        if(this->isNegative&&!other.isNegative)return-((-*this)+other);
        if(!this->isNegative&&other.isNegative)return *this+(-other);
        bool resultNegative=false;
        const BigInteger* larger=this;
        const BigInteger* smaller=&other;
        if(this->digits.size()<other.digits.size()||(this->digits.size()==other.digits.size()&&this->digits<other.digits)){
            resultNegative=!this->isNegative;
            larger=&other;
            smaller=this;
        }
        BigInteger result("0");
        result.isNegative=resultNegative;
        int borrow=0;
        for(size_t i=0;i<larger->digits.size();++i){
            int sub=larger->digits[i]-borrow;
            if(i<smaller->digits.size())sub-=smaller->digits[i];
            if(sub<0){
                sub+=10;
                borrow=1;
            }else borrow=0;
            result.digits.push_back(sub);
        }
        result.removeLeadingZeros();
        return result;
    }
    friend ostream& operator<<(ostream& os,const BigInteger& bigInt) {
        if(bigInt.isNegative&&bigInt.digits.size()>0)os<<'-';
        for(int i=bigInt.digits.size()-1;i>=0;--i)os<<bigInt.digits[i];
        return os;
    }
    friend istream& operator>>(istream& is,BigInteger& bigInt) {
        string number;
        is>>number;
        bigInt=BigInteger(number);
        return is;
    }
    bool operator==(const BigInteger& other) const {
        return isNegative==other.isNegative&&digits==other.digits;
    }
    bool operator!=(const BigInteger& other) const {
        return!(*this==other);
    }
    BigInteger operator-() const {
        BigInteger result=*this;
        if(result.digits.size()==1&&result.digits[0]==0)result.isNegative=false;
        else result.isNegative=!this->isNegative;
        return result;
    }
};
int main() {
    BigInteger num1("12345678901234567890");
    BigInteger num2("98765432109876543210");
    BigInteger sum=num1+num2;
    BigInteger difference=num1-num2;
    cout<<"Sum: "<<sum<<endl;
    cout<<"Difference: "<<difference<<endl;
    return 0;
}

