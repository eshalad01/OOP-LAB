#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix{
private:
    int rows;
    int cols;
    int value[10][10];

public:
    Matrix(){}
    Matrix(int rows, int cols){
        this->rows=rows;
        this->cols=cols;
    }

    int getRows(){
        return rows;
    }

    int getCols(){
        return cols;
    }

    void setElement(int i,int j,int newValue){
        if(i>=0 && i<rows && j>=0 && j<cols) {
            value[i][j]=newValue;
        }
    }

    void display(){
        for (int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                cout<<value[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    Matrix add(Matrix temp) {
        if(rows!=temp.rows||cols!=temp.cols){
            cout<<"Matrices cannot be added"<<endl;
            return Matrix(0,0);
        }
        Matrix result(rows, cols);
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                result.setElement(i,j,value[i][j]+temp.value[i][j]);
            }
        }
        return result;
    }

    Matrix multiply(Matrix temp) {
        if(cols!=temp.rows) {
            cout<<"Matrices cannot be multiplied"<<endl;
            return Matrix(0,0);
        }
        Matrix result(rows,temp.cols);
        for(int i=0;i<rows;i++) {
            for(int j=0;j<temp.cols;j++) {
                int sum = 0;
                for(int k=0;k<cols;k++) {
                    sum+=value[i][k]*temp.value[k][j];
                }
                result.setElement(i,j,sum);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    if (argc<9) {
        cout<<"Invalid Inputs"<<endl;
        return 1;
    }
    Matrix A(2,2);
    Matrix B(2,2);

    int index=1;
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            A.setElement(i,j,stoi(argv[index++]));
        }
    }
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            B.setElement(i,j,stoi(argv[index++]));
        }
    }
    cout<<"Matrix A:"<<endl;
    A.display();
    cout<<"Matrix B:"<<endl;
    B.display();

    cout<<"Addition Result:"<<endl;
    Matrix C=A.add(B);
    C.display();

    cout<<"Multiplication Result:"<<endl;
    Matrix D=A.multiply(B);
    D.display();

    return 0;
}

