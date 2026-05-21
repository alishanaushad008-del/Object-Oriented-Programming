#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class Person {
public:
    char name[50];
    int age;

    Person() {}
    Person(string n, int a) {
        strcpy(name, n.c_str());
        age = a;
    }
};

int main() {
    Person person1("Alisha", 25);

    ofstream outFile("person.bin", ios::binary);
    outFile.write((char*)&person1, sizeof(person1));
    outFile.close();

    Person person2;
    ifstream inFile("person.bin", ios::binary);
    inFile.read((char*)&person2, sizeof(person2));
    inFile.close();

    cout << "Read Name: " << person2.name << endl;
    cout << "Read Age: " << person2.age << endl;

    return 0;
}