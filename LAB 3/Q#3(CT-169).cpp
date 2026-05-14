#include <iostream>
#include <iomanip>
using namespace std;

class Tollbooth {
private:
    int totalCars;
    double totalCash;

public:
    Tollbooth() : totalCars(0), totalCash(0.0) {}

    void payingCar() {
        totalCars++;
        totalCash += 0.50;
    }

    void display() const {
        cout << "Cars: " << totalCars << endl;
        cout << "Cash: $" << fixed << setprecision(2) << totalCash << endl;
    }
};

int main() {
    Tollbooth booth;
    booth.payingCar();
    booth.payingCar();
    booth.display();
    return 0;
}