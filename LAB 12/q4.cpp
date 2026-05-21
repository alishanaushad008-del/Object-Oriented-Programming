#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class Participant {
public:
    int id;
    char name[50];
    int score;

    void Input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Score: ";
        cin >> score;

        ofstream outFile("participant.dat", ios::binary | ios::app);
        if (outFile) {
            outFile.write(reinterpret_cast<char*>(this), sizeof(Participant));
            outFile.close();
        }
    }

    void Output() {
        int searchId;
        cout << "Enter ID to search: ";
        cin >> searchId;

        ifstream inFile("participant.dat", ios::binary);
        if (!inFile) {
            cout << "No data file found." << endl;
            return;
        }

        Participant p;
        bool found = false;

        while (inFile.read(reinterpret_cast<char*>(&p), sizeof(Participant))) {
            if (p.id == searchId) {
                cout << "ID: " << p.id << "\nName: " << p.name << "\nScore: " << p.score << endl;
                found = true;
                break;
            }
        }
        inFile.close();

        if (!found) {
            cout << "Participant not found." << endl;
        }
    }

    void Max() {
        ifstream inFile("participant.dat", ios::binary);
        if (!inFile) {
            cout << "No data file found." << endl;
            return;
        }

        Participant p;
        Participant maxP;
        int maxScore = -1;
        bool empty = true;

        while (inFile.read(reinterpret_cast<char*>(&p), sizeof(Participant))) {
            empty = false;
            if (p.score > maxScore) {
                maxScore = p.score;
                maxP = p;
            }
        }
        inFile.close();

        if (!empty) {
            cout << "Highest Score Participant:\nID: " << maxP.id << "\nName: " << maxP.name << "\nScore: " << maxP.score << endl;
        } else {
            cout << "No data in file." << endl;
        }
    }
};

int main() {
    Participant p;
    int choice;

    while (true) {
        cout << "\n1. Input Data\n2. Output Data by ID\n3. Show Max Score\n4. Exit\nChoice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Please enter a number." << endl;
            continue;
        }

        if (choice == 1) p.Input();
        else if (choice == 2) p.Output();
        else if (choice == 3) p.Max();
        else if (choice == 4) break;
        else cout << "Invalid choice." << endl;
    }

    return 0;
}