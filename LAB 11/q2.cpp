#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {
private:
    vector<char> elements;

public:
    void push(char c) {
        elements.push_back(c);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
    }

    char peek() {
        if (!elements.empty()) {
            return elements.back();
        }
        return '\0';
    }

    bool isEmpty() {
        return elements.empty();
    }

    string reverse(string sentence) {
        string result = "";
        for (int i = 0; i <= sentence.length(); i++) {
            if (i == sentence.length() || sentence[i] == ' ') {
                while (!isEmpty()) {
                    result += peek();
                    pop();
                }
                if (i < sentence.length()) {
                    result += " ";
                }
            } else {
                push(sentence[i]);
            }
        }
        return result;
    }
};

int main() {
    Stack s;
    string sentence;
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    
    string reversedSentence = s.reverse(sentence);
    cout << "Reversed: " << reversedSentence << endl;
    
    return 0;
}