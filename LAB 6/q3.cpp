#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    double x, y;
public:
    Vector(double x = 0.0, double y = 0.0) {
        this->x = x;
        this->y = y;
    }

    Vector operator+(const Vector& obj) const {
        return Vector(x + obj.x, y + obj.y);
    }

    Vector operator-(const Vector& obj) const {
        return Vector(x - obj.x, y - obj.y);
    }

    Vector operator*(double scalar) const {
        return Vector(x * scalar, y * scalar);
    }

    Vector operator/(double scalar) const {
        if (scalar == 0) {
            cout << "Error: Division by zero" << endl;
            return Vector(0, 0);
        }
        return Vector(x / scalar, y / scalar);
    }

    double magnitude() const {
        return sqrt(x * x + y * y);
    }

    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vector v1(10.5, 5.5);
    Vector v2(2.5, 1.5);

    (v1 + v2).display();
    (v1 - v2).display();
    (v1 * 2.5).display();
    (v1 / 2.0).display();

    cout << v1.magnitude() << endl;

    return 0;
}