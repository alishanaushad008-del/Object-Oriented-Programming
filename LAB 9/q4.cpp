#include <iostream>
#include <string>
using namespace std;

class EncryptionTechnique {
public:
    virtual void encrypt(string message) = 0;
};

class EncryptionTechnique1 : public EncryptionTechnique {
public:
    void encrypt(string message) {
        string result = "";

        for (int i = 0; i < message.length(); i++) {
            result += to_string((int)message[i]);
        }

        cout << "Technique 1 Encryption: " << result << endl;
    }
};

class EncryptionTechnique2 : public EncryptionTechnique {
public:
    void encrypt(string message) {
        string result = "";

        for (int i = 0; i < message.length(); i++) {
            result += to_string((int)message[i] + 2);
        }

        cout << "Technique 2 Encryption: " << result << endl;
    }
};

int main() {
    string message;

    cout << "Enter Message: ";
    getline(cin, message);

    EncryptionTechnique *e1;
    EncryptionTechnique *e2;

    e1 = new EncryptionTechnique1();
    e2 = new EncryptionTechnique2();

    e1->encrypt(message);
    e2->encrypt(message);

    delete e1;
    delete e2;

    return 0;
}