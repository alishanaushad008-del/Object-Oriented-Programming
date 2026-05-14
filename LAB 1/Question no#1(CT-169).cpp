//Question no#1
#include<iostream>
using namespace std;

int main(){
    int roll;
    float x1, x2, x3, x4, x5, total_marks, percentage;

    cout << "Enter your roll no: ";
    cin >> roll;

    cout << "Enter marks of first subject: ";
    cin >> x1;
    cout << "Enter marks of second subject: ";
    cin >> x2;
    cout << "Enter marks of third subject: ";
    cin >> x3;
    cout << "Enter marks of fourth subject: ";
    cin >> x4;
    cout << "Enter marks of fifth subject: ";
    cin >> x5;

    total_marks = x1 + x2 + x3 + x4 + x5;
    percentage = (total_marks / 500) * 100;

    cout << "Roll Number: " << roll << endl;
    cout << "Total marks are: " << total_marks << endl;
    cout << "Percentage is: " << percentage << "%" << endl;
}