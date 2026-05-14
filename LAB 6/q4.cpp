#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string occupation;
public:
    Person(string _occupation) {
        occupation = _occupation;
    }
    virtual ~Person() {}
    virtual void Draw() {
        cout << "A person can draw in many ways" << endl;
    }
};

class Artist : public Person {
public:
    Artist() : Person("Artist") {}
    void Draw() {
        cout << "An artist can draw with a paint brush" << endl;
    }
};

class Gunman : public Person {
public:
    Gunman() : Person("Gunman") {}
    void Draw() {
        cout << "A gunman draws a gun to shoot" << endl;
    }
};

int main() {
    Person* arr[3];

    arr[0] = new Person("Unknown");
    arr[1] = new Artist();
    arr[2] = new Gunman();

    for (int i = 0; i < 3; i++) {
        arr[i]->Draw();
    }

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }

    return 0;
}