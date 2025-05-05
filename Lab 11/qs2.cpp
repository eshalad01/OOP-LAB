#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class DimensionMismatchException : public runtime_error {
public:
    DimensionMismatchException(const string& message)
        : runtime_error(message) {}
};

template <typename T>
class Matrix {
private:
    vector<vector<T> > data;
    size_t rows, cols;
public:
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        data.resize(rows, vector<T>(cols));
    }

    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols) {
            throw out_of_range("Index out of bounds");
        }
        return data[r][c];
    }

    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols) {
            throw out_of_range("Index out of bounds");
        }
        return data[r][c];
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException("Matrix dimensions must match for addition.");
        }
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.at(i, j) = this->at(i, j) + other.at(i, j);
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) {
            throw DimensionMismatchException("Matrix dimensions are not compatible for multiplication.");
        }
        Matrix<T> result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.at(i, j) += this->at(i, k) * other.at(k, j);
                }
            }
        }
        return result;
    }
};
int main() {
    Matrix<int> a(2, 2), b(2, 2);
    a.at(0,0) = 1; a.at(0,1) = 2;
    a.at(1,0) = 3; a.at(1,1) = 4;

    b.at(0,0) = 5; b.at(0,1) = 6;
    b.at(1,0) = 7; b.at(1,1) = 8;

    Matrix<int> c = a + b;

    cout << "Result matrix:" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << c.at(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}

