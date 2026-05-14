#include <iostream>
using namespace std;

template <class T1, class T2>
void swapData(T1 &a, T2 &b) {
    T1 temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    double y = 20.5;

    cout << "Before Swapping:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    swapData(x, y);

    cout << "\nAfter Swapping:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}