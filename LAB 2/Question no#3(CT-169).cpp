#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Employee {
private:
    char* firstName;     // Dynamic Memory Allocation
    string lastName;
    int monthlySalary;

public:
    // Default Constructor
    Employee() {
        firstName = nullptr;
        monthlySalary = 0;
    }

    // Parameterized Setter
    void setEmployee(const char* fName, string lName, int salary) {
        // Delete old memory if any
        delete[] firstName;

        // Allocate memory for first name
        firstName = new char[strlen(fName) + 1];
        strcpy(firstName, fName);

        lastName = lName;

        if (salary > 0)
            monthlySalary = salary;
        else
            monthlySalary = 0;
    }

    // Copy Constructor (Rule of Three)
    Employee(const Employee& obj) {
        firstName = new char[strlen(obj.firstName) + 1];
        strcpy(firstName, obj.firstName);
        lastName = obj.lastName;
        monthlySalary = obj.monthlySalary;
    }

    // Copy Assignment Operator (Rule of Three)
    Employee& operator=(const Employee& obj) {
        if (this != &obj) {
            delete[] firstName;

            firstName = new char[strlen(obj.firstName) + 1];
            strcpy(firstName, obj.firstName);

            lastName = obj.lastName;
            monthlySalary = obj.monthlySalary;
        }
        return *this;
    }

    // Getter Functions
    char* getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    int getMonthlySalary() const {
        return monthlySalary;
    }

    // Calculate Yearly Salary
    int getYearlySalary() const {
        return monthlySalary * 12;
    }

    // Give 10% Raise
    void giveRaise() {
        monthlySalary += monthlySalary * 10 / 100;
    }

    // Destructor (Rule of Three)
    ~Employee() {
        delete[] firstName;
    }
};

int main() {
    Employee emp1, emp2;

    // Initialize employees
    emp1.setEmployee("Alisha", "Khan", 50000);
    emp2.setEmployee("Sana", "Ali", 60000);

    // Display yearly salary before raise
    cout << "Before Raise:\n";
    cout << emp1.getFirstName() << " " << emp1.getLastName()
         << " Yearly Salary: " << emp1.getYearlySalary() << endl;

    cout << emp2.getFirstName() << " " << emp2.getLastName()
         << " Yearly Salary: " << emp2.getYearlySalary() << endl;

    // Give 10% raise
    emp1.giveRaise();
    emp2.giveRaise();

    // Display yearly salary after raise
    cout << "\nAfter 10% Raise:\n";
    cout << emp1.getFirstName() << " " << emp1.getLastName()
         << " Yearly Salary: " << emp1.getYearlySalary() << endl;

    cout << emp2.getFirstName() << " " << emp2.getLastName()
         << " Yearly Salary: " << emp2.getYearlySalary() << endl;

    return 0;
}