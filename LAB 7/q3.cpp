#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int id;
    string designation;
    double salary;

public:
    Employee(string n, int i, string d, double s) {
        name = n;
        id = i;
        designation = d;
        salary = s;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: " << salary << endl;
    }

    friend class Payroll;
};

class Payroll {
public:
    void updateSalary(Employee &e, double increment) {
        e.salary += increment;
    }
};

int main() {
    Employee emp("Ali", 101, "Manager", 50000);

    cout << "Before Update:\n";
    emp.display();

    Payroll p;
    p.updateSalary(emp, 10000);

    cout << "\nAfter Update:\n";
    emp.display();

    return 0;
}