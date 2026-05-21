#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int length = 0;
    for (char c : str) {
        length++;
    }
    cout << "Length of the string: " << length << endl;

    ofstream outFile("chars.txt");
    outFile << str;
    outFile.close();

    ifstream inFile("chars.txt");
    char ch;
    cout << "Fetched characters from file: ";
    while (inFile.get(ch)) {
        cout << ch;
    }
    cout << endl;
    inFile.close();

    return 0;
}