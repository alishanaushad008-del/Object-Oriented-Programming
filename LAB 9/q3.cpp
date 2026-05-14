#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int carId;
    string brand;
    string model;

public:
    Vehicle(int id, string b, string m) {
        carId = id;
        brand = b;
        model = m;
    }

    virtual bool isAvailable() = 0;
    virtual void rent() = 0;
    virtual void returnVehicle() = 0;
    virtual void display() = 0;

    virtual ~Vehicle() {
    }
};

class Car : public Vehicle {
private:
    bool available;

public:
    Car(int id, string b, string m) : Vehicle(id, b, m) {
        available = true;
    }

    bool isAvailable() {
        return available;
    }

    void rent() {
        if (available) {
            available = false;
            cout << "Car Rented Successfully" << endl;
        }
        else {
            cout << "Car Not Available" << endl;
        }
    }

    void returnVehicle() {
        available = true;
        cout << "Car Returned Successfully" << endl;
    }

    void display() {
        cout << "Car ID: " << carId << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;

        if (available)
            cout << "Status: Available" << endl;
        else
            cout << "Status: Rented" << endl;

        cout << endl;
    }
};

class RentalSystem {
public:
    void rentVehicle(Vehicle *v) {
        if (v->isAvailable()) {
            v->rent();
        }
        else {
            cout << "Vehicle Already Rented" << endl;
        }
    }

    void returnVehicle(Vehicle *v) {
        v->returnVehicle();
    }
};

class Customer {
private:
    string name;

public:
    Customer(string n) {
        name = n;
    }

    void rentVehicle(RentalSystem &rs, Vehicle *v) {
        cout << name << " wants to rent a vehicle." << endl;
        rs.rentVehicle(v);
    }

    void returnVehicle(RentalSystem &rs, Vehicle *v) {
        cout << name << " returned the vehicle." << endl;
        rs.returnVehicle(v);
    }
};

int main() {
    Vehicle *vehicles[2];

    vehicles[0] = new Car(101, "Toyota", "Corolla");
    vehicles[1] = new Car(102, "Honda", "Civic");

    RentalSystem system;

    Customer c1("Ali");

    for (int i = 0; i < 2; i++) {
        vehicles[i]->display();
    }

    c1.rentVehicle(system, vehicles[0]);

    vehicles[0]->display();

    c1.returnVehicle(system, vehicles[0]);

    vehicles[0]->display();

    for (int i = 0; i < 2; i++) {
        delete vehicles[i];
    }

    return 0;
}