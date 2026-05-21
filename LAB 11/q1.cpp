#include <iostream>
#include <string>
#include <exception>

using namespace std;

class InvalidPasswordException : public exception {
public:
    const char* what() const throw() {
        return "Exception: Password must be at least 6 characters and contain a digit.";
    }
};

void validatePassword(string password) {
    if (password.length() < 6) {
        throw InvalidPasswordException();
    }
    
    bool hasDigit = false;
    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
            break;
        }
    }
    
    if (!hasDigit) {
        throw InvalidPasswordException();
    }
}

int main() {
    string username, password;
    
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    try {
        validatePassword(password);
        cout << "Login successful!" << endl;
    } catch (const InvalidPasswordException& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}