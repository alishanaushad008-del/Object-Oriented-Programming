#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class DecryptionTechnique {
public:
    virtual void decrypt(string code) = 0;
};

class DecryptionTechnique1 : public DecryptionTechnique {
public:
    void decrypt(string code) {
        stringstream ss(code);
        int value;
        string result = "";

        while (ss >> value) {
            result += char(value);
        }

        cout << "Technique 1 Decryption: " << result << endl;
    }
};

class DecryptionTechnique2 : public DecryptionTechnique {
public:
    void decrypt(string code) {
        stringstream ss(code);
        int value;
        string result = "";

        while (ss >> value) {
            result += char(value - 2);
        }

        cout << "Technique 2 Decryption: " << result << endl;
    }
};

int main() {
    string code1, code2;

    cout << "Enter Encrypted String for Technique 1: ";
    getline(cin, code1);

    cout << "Enter Encrypted String for Technique 2: ";
    getline(cin, code2);

    DecryptionTechnique *d1;
    DecryptionTechnique *d2;

    d1 = new DecryptionTechnique1();
    d2 = new DecryptionTechnique2();

    d1->decrypt(code1);
    d2->decrypt(code2);

    delete d1;
    delete d2;

    return 0;
}