#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void countLines() {
    ifstream inFile("STORY.TXT");
    string line;
    int count = 0;

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(inFile, line)) {
        if (!line.empty() && line[0] != 'A') {
            count++;
        }
    }
    inFile.close();

    cout << "Output: " << count << endl;
}

int main() {
    ofstream outFile("STORY.TXT");
    outFile << "The rose is red.\nA girl is playing there.\nThere is a playground.\nAn airplane is in the sky.\nNumbers are not allowed in the password.\n";
    outFile.close();

    countLines();

    return 0;
}