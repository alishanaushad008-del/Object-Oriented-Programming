#include <iostream>
using namespace std;

class Shape {
protected:
    int numberOfSides;
    double area;
public:
    Shape(int n, double a) {
        numberOfSides = n;
        area = a;
    }
    virtual void generateArea() = 0;
};

class Rectangle : public Shape {
protected:
    double length, width;
public:
    Rectangle(double l, double w) : Shape(4, 0.0) {
        length = l;
        width = w;
    }
    void generateArea() {
        area = length * width;
        cout << "Rectangle Area: " << area << endl;
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : Shape(0, 0.0) {
        radius = r;
    }
    void generateArea() {
        area = 3.14159 * radius * radius;
        cout << "Circle Area: " << area << endl;
    }
};

class Triangle : public Shape {
    double height, base;
public:
    Triangle(double h, double b) : Shape(3, 0.0) {
        height = h;
        base = b;
    }
    void generateArea() {
        area = 0.5 * base * height;
        cout << "Triangle Area: " << area << endl;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    void checkSides() {
        if (length == width) {
            cout << "It is a valid square." << endl;
        }
    }
    void generateArea() {
        area = length * width;
        cout << "Square Area: " << area << endl;
    }
};

int main() {
    Shape* s;

    Rectangle rect(10, 5);
    Circle circ(4);
    Triangle tri(4, 6);
    Square sq(5);

    s = &rect;
    s->generateArea();

    s = &circ;
    s->generateArea();

    s = &tri;
    s->generateArea();

    s = &sq;
    s->generateArea();
    sq.checkSides();

    return 0;
}