#include <iostream>
using namespace std;

class Calculator {
private:
    double Num1, Num2, Num3;
public:
    Calculator() {
        cout << "Enter number 1: ";
        cin >> Num1;
        cout << "Enter number 2: ";
        cin >> Num2;
        cout << "Enter number 3: ";
        cin >> Num3;
    }

    double getNum1() { return Num1; }
    double getNum2() { return Num2; }
    double getNum3() { return Num3; }

    double add(double a, double b) { return a + b; }
    double add(double a, double b, double c) { return a + b + c; }

    double multiply(double a, double b) { return a * b; }
    double multiply(double a, double b, double c) { return a * b * c; }

    double subtract(double a, double b) { return a - b; }
    double subtract(double a, double b, double c) { return a - b - c; }

    double divide(double a, double b) {
        if (b == 0) {
            cout << "Error: Division by zero" << endl;
            return 0;
        }
        return a / b;
    }

    double divide(double a, double b, double c) {
        if (b == 0 || c == 0) {
            cout << "Error: Division by zero" << endl;
            return 0;
        }
        return a / b / c;
    }
};

int main() {
    Calculator calc;

    double n1 = calc.getNum1();
    double n2 = calc.getNum2();
    double n3 = calc.getNum3();

    cout << calc.add(n1, n2) << endl;
    cout << calc.add(n1, n2, n3) << endl;

    cout << calc.multiply(n1, n2) << endl;
    cout << calc.multiply(n1, n2, n3) << endl;

    cout << calc.subtract(n1, n2) << endl;
    cout << calc.subtract(n1, n2, n3) << endl;

    cout << calc.divide(n1, n2) << endl;
    cout << calc.divide(n1, n2, n3) << endl;

    return 0;
}