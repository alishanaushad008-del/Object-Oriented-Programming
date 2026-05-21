#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, char> studentGrades;
    int choice;
    string name;
    char grade;

    while (true) {
        cout << "\n1. Add Student\n2. Retrieve Grade\n3. Update Grade\n4. Delete Student\n5. Display All\n6. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter grade: ";
            cin >> grade;
            studentGrades[name] = grade;
        } 
        else if (choice == 2) {
            cout << "Enter name: ";
            cin >> name;
            if (studentGrades.find(name) != studentGrades.end()) {
                cout << "Grade: " << studentGrades[name] << endl;
            } else {
                cout << "Student not found." << endl;
            }
        } 
        else if (choice == 3) {
            cout << "Enter name: ";
            cin >> name;
            if (studentGrades.find(name) != studentGrades.end()) {
                cout << "Enter new grade: ";
                cin >> grade;
                studentGrades[name] = grade;
            } else {
                cout << "Student not found." << endl;
            }
        } 
        else if (choice == 4) {
            cout << "Enter name: ";
            cin >> name;
            if (studentGrades.erase(name)) {
                cout << "Student deleted." << endl;
            } else {
                cout << "Student not found." << endl;
            }
        } 
        else if (choice == 5) {
            cout << "Student Grades:" << endl;
            for (auto const& pair : studentGrades) {
                cout << pair.first << ": " << pair.second << endl;
            }
        } 
        else if (choice == 6) {
            break;
        } 
        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}