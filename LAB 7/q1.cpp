#include <iostream>
using namespace std;

class Array2D {
    int rows, cols;
    int** data;

public:
    Array2D() {
        rows = cols = 0;
        data = nullptr;
    }

    Array2D(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols];
    }

    Array2D(const Array2D& obj) {
        rows = obj.rows;
        cols = obj.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = obj.data[i][j];
        }
    }

    Array2D& operator=(const Array2D& obj) {
        if (this != &obj) {
            for (int i = 0; i < rows; i++)
                delete[] data[i];
            delete[] data;

            rows = obj.rows;
            cols = obj.cols;
            data = new int*[rows];
            for (int i = 0; i < rows; i++) {
                data[i] = new int[cols];
                for (int j = 0; j < cols; j++)
                    data[i][j] = obj.data[i][j];
            }
        }
        return *this;
    }

    Array2D operator+(const Array2D& obj) {
        Array2D res(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res.data[i][j] = data[i][j] + obj.data[i][j];
        return res;
    }

    Array2D operator-(const Array2D& obj) {
        Array2D res(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                res.data[i][j] = data[i][j] - obj.data[i][j];
        return res;
    }

    Array2D operator*(const Array2D& obj) {
        Array2D res(rows, obj.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < obj.cols; j++) {
                res.data[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    res.data[i][j] += data[i][k] * obj.data[k][j];
            }
        return res;
    }

    int* operator[](int i) {
        return data[i];
    }

    void input() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    ~Array2D() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }
};

int main() {
    Array2D A(2,2), B(2,2);

    cout << "Enter A:\n";
    A.input();

    cout << "Enter B:\n";
    B.input();

    Array2D C = A + B;
    cout << "\nA+B:\n";
    C.display();

    cout << "\nElement A[0][1]: " << A[0][1] << endl;

    return 0;
}