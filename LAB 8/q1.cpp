#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string typeOfCar, make, model, color;
    int year;
    double milesDriven;

public:
    Vehicle(string t, string mk, string md, string c, int y, double m)
        : typeOfCar(t), make(mk), model(md), color(c), year(y), milesDriven(m) {}

    void displayVehicle() const {
        cout << "Type: " << typeOfCar << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Miles Driven: " << milesDriven << endl;
    }
};

class GasVehicle : virtual public Vehicle {
private:
    double fuelTankSize;

public:
    GasVehicle(string t, string mk, string md, string c, int y, double m, double fts)
        : Vehicle(t, mk, md, c, y, m), fuelTankSize(fts) {}

    void displayGas() const {
        cout << "Fuel Tank Size: " << fuelTankSize << endl;
    }
};

class ElectricVehicle : virtual public Vehicle {
private:
    double energyStorage;

public:
    ElectricVehicle(string t, string mk, string md, string c, int y, double m, double es)
        : Vehicle(t, mk, md, c, y, m), energyStorage(es) {}

    void displayElectric() const {
        cout << "Energy Storage: " << energyStorage << endl;
    }
};

class HighPerformance : public GasVehicle {
private:
    int horsePower, topSpeed;

public:
    HighPerformance(string t, string mk, string md, string c, int y, double m, double fts, int hp, int ts)
        : Vehicle(t, mk, md, c, y, m), GasVehicle(t, mk, md, c, y, m, fts), horsePower(hp), topSpeed(ts) {}

    void displayHighPerformance() const {
        cout << "Horse Power: " << horsePower << endl;
        cout << "Top Speed: " << topSpeed << endl;
    }
};

class SportsCar : public HighPerformance {
public:
    string gearbox, driveSystem;

    SportsCar(string t, string mk, string md, string c, int y, double m, double fts, int hp, int ts, string gb, string ds)
        : Vehicle(t, mk, md, c, y, m), HighPerformance(t, mk, md, c, y, m, fts, hp, ts), gearbox(gb), driveSystem(ds) {}

    void displaySportsCar() const {
        displayHighPerformance();
        cout << "Gearbox: " << gearbox << endl;
        cout << "Drive System: " << driveSystem << endl;
    }
};

class HeavyVehicle : public GasVehicle, public ElectricVehicle {
private:
    double maximumWeight, length;
    int numberOfWheels;

public:
    HeavyVehicle(string t, string mk, string md, string c, int y, double m, double fts, double es, double mw, int nw, double len)
        : Vehicle(t, mk, md, c, y, m), GasVehicle(t, mk, md, c, y, m, fts), ElectricVehicle(t, mk, md, c, y, m, es),
          maximumWeight(mw), numberOfWheels(nw), length(len) {}

    void displayHeavy() const {
        cout << "Maximum Weight: " << maximumWeight << endl;
        cout << "Number of Wheels: " << numberOfWheels << endl;
        cout << "Length: " << length << endl;
    }
};

class ConstructionTruck : public HeavyVehicle {
public:
    string cargo;

    ConstructionTruck(string t, string mk, string md, string c, int y, double m, double fts, double es, double mw, int nw, double len, string cg)
        : Vehicle(t, mk, md, c, y, m), HeavyVehicle(t, mk, md, c, y, m, fts, es, mw, nw, len), cargo(cg) {}

    void displayConstructionTruck() const {
        displayHeavy();
        cout << "Cargo: " << cargo << endl;
    }
};

class Bus : public HeavyVehicle {
private:
    int numberOfSeats;

public:
    Bus(string t, string mk, string md, string c, int y, double m,
        double fts, double es, double mw, int nw, double len, int ns)
        : Vehicle(t, mk, md, c, y, m), HeavyVehicle(t, mk, md, c, y, m, fts, es, mw, nw, len), numberOfSeats(ns) {}

    void display() const {
        displayVehicle();
        displayGas();
        displayElectric();
        displayHeavy();
        cout << "Number of Seats: " << numberOfSeats << endl;
    }
};

int main() {
    Bus myBus("Passenger Bus", "Volvo", "9700", "White",
              2023, 12500.5,
              150.0, 300.0,
              35000.0, 6, 45.5,
              54);

    myBus.display();

    return 0;
}