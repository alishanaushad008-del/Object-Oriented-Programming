
#include <iostream>
using namespace std;

class ArrayMultiplier {
public:
    virtual void calculate() = 0;
};

class ArrayMultiplier1D : public ArrayMultiplier {
private:
    int arr[5];

public:
    ArrayMultiplier1D() {
        for (int i = 0; i < 5; i++) {
            cin >> arr[i];
        }
    }

    void calculate() {
        int product = 1;

        for (int i = 0; i < 5; i++) {
            product *= arr[i];
        }

        cout << "1D Array Multiplication = " << product << endl;
    }
};

class ArrayMultiplier2D : public ArrayMultiplier {
private:
    int arr[2][2];

public:
    ArrayMultiplier2D() {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> arr[i][j];
            }
        }
    }

    void calculate() {
        int product = 1;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                product *= arr[i][j];
            }
        }

        cout << "2D Array Multiplication = " << product << endl;
    }
};

int main() {
    cout << "Enter 5 elements for 1D array:" << endl;
    ArrayMultiplier1D obj1;
    obj1.calculate();

    cout << "Enter 4 elements for 2D array:" << endl;
    ArrayMultiplier2D obj2;
    obj2.calculate();

    return 0;
}