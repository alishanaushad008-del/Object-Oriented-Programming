#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream makeSource("source.txt");
    makeSource << "Hello! This text is copied from source to destination.";
    makeSource.close();

    ifstream source("source.txt");
    ofstream destination("destination.txt");

    if (!source) {
        cout << "Error opening source file!" << endl;
        return 1;
    }

    char ch;
    while (source.get(ch)) {
        destination.put(ch);
    }

    cout << "File copied successfully." << endl;

    source.close();
    destination.close();
    return 0;
}