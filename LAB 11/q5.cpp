#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> guests;
    string name;
    int choice;

    while (true) {
        cout << "\n1. Add Guest\n2. Display Guests\n3. Count Guests\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter guest name: ";
            cin >> name;
            guests.insert(name);
            cout << "Guest added." << endl;
        } 
        else if (choice == 2) {
            cout << "Guest List:" << endl;
            for (const string& guest : guests) {
                cout << guest << endl;
            }
        } 
        else if (choice == 3) {
            cout << "Total unique guests: " << guests.size() << endl;
        } 
        else if (choice == 4) {
            break;
        } 
        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}