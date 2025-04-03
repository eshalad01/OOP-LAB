#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial;

class PolynomialUtils{
public:
    static int evaluate(const Polynomial &p, int x);
    static Polynomial derivative(const Polynomial &p);
};

class Polynomial {
    friend class PolynomialUtils;
private:
    vector<int>coefficients;

public:
    Polynomial() {}
    Polynomial(const vector<int> &coeffs) : coefficients(coeffs) {}
    Polynomial operator+(const Polynomial &other) {
        size_t maxSize=max(coefficients.size(), other.coefficients.size());
        vector<int> result(maxSize,0);

        for (int i=0; i<maxSize; ++i) {
            if (i<coefficients.size()) result[i]+=coefficients[i];
            if (i<other.coefficients.size()) result[i]+=other.coefficients[i];
        }
        return Polynomial(result);
    }
    Polynomial operator-(const Polynomial &other) {
        size_t maxSize=max(coefficients.size(),other.coefficients.size());
        vector<int> result(maxSize,0);

        for (int i=0; i<maxSize;++i) {
            if (i<coefficients.size()) result[i]+=coefficients[i];
            if (i<other.coefficients.size()) result[i]- other.coefficients[i];
        }
        return Polynomial(result);
    }
    Polynomial operator*(const Polynomial &other) {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);

        for (int i=0; i<coefficients.size();++i) {
            for (int j=0; j<other.coefficients.size(); ++j) {
                result[i+j]+=coefficients[i]*other.coefficients[j];
            }
        }
        return Polynomial(result);
    }
    friend ostream& operator<<(ostream &os, const Polynomial &p) {
        bool first=true;
        for (int i=0;i<p.coefficients.size(); ++i) {
            if (p.coefficients[i] != 0) {
                if (!first && p.coefficients[i]>0)os<<" + ";
                if (p.coefficients[i]<0)os<< " - ";
                os<<abs(p.coefficients[i]);
                if (i>0)os<<"x^"<<i;
                first=false;
            }
        }
        return os;
    }
};
int PolynomialUtils::evaluate(const Polynomial &p, int x) {
    int result=0;
    for (int i=0;i<p.coefficients.size();++i) {
        result+=p.coefficients[i]*pow(x, i);
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p) {
    vector<int> derivCoeffs;
    for (int i=1;i<p.coefficients.size(); ++i) {
        derivCoeffs.push_back(i*p.coefficients[i]);
    }
    return Polynomial(derivCoeffs);
}

int main() {
    Polynomial p1({1, 2, 3});  
    Polynomial p2({4, 5, 6});  
    cout<<"p1 + p2 = "<< p1+ p2<<endl;
    cout<<"p1 - p2 = "<< p1-p2<<endl;
    cout<<"p1 * p2 = "<< p1*p2<<endl;
    cout<<"p1 evaluated at x = 2: "<<PolynomialUtils::evaluate(p1, 2) << endl;

    return 0;
}

