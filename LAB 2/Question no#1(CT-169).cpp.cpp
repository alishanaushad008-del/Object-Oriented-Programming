#include <iostream>
#include <string>
using namespace std;

class student {
public:
    string name;
    int roll_no;
    int semester;
    char section;
};

int main() {
    // Creating 4 student objects
    student s1 = {"Ali", 101, 2, 'A'};
    student s2 = {"Sara", 102, 2, 'B'};
    student s3 = {"Ahmed", 103, 3, 'A'};
    student s4 = {"Zara", 104, 1, 'C'};

    student students[4] = {s1, s2, s3, s4};

    cout << "Students belonging to Section A:\n\n";

    for (int i = 0; i < 4; i++) {
        if (students[i].section == 'A') {
            cout << "Name: " << students[i].name << endl;
            cout << "Roll No: " << students[i].roll_no << endl;
            cout << "Semester: " << students[i].semester << endl;
            cout << "Section: " << students[i].section << endl;
            cout << "------------------------\n";
        }
    }

}