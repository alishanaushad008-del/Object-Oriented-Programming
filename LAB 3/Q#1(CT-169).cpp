#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double* real;
    double* imag;

public:
    ComplexNumber(double r, double i) {
        real = new double(r);
        imag = new double(i);
    }

    ComplexNumber(const ComplexNumber& source) {
        real = new double(*source.real);
        imag = new double(*source.imag);
    }

    ~ComplexNumber() {
        delete real;
        delete imag;
    }

    void display() const {
        cout << *real << " + " << *imag << "i" << endl;
    }
};

int main() {
    ComplexNumber num1(5.5, 3.2);
    ComplexNumber num2 = num1;
    num1.display();
    num2.display();
    return 0;
}