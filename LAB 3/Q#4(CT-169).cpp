#include <iostream>
#include <string>
using namespace std;

class bookType {
private:
    string title;
    string authors[4];
    int numAuthors;
    string publisher;
    string ISBN;
    double price;
    int stock;

public:
    // Default constructor
    bookType() {
        title = "";
        publisher = "";
        ISBN = "";
        price = 0.0;
        stock = 0;
        numAuthors = 0;
    }

    // Setters
    void setTitle(string t) { title = t; }
    void setPublisher(string p) { publisher = p; }
    void setISBN(string i) { ISBN = i; }
    void setPrice(double p) { price = p; }
    void setStock(int s) { stock = s; }

    void setAuthors(string auth[], int count) {
        numAuthors = (count > 4) ? 4 : count;
        for (int i = 0; i < numAuthors; i++)
            authors[i] = auth[i];
    }

    // Getters
    string getTitle() const { return title; }
    string getISBN() const { return ISBN; }
    int getStock() const { return stock; }

    // Operations
    bool isTitleSame(string t) const {
        return title == t;
    }

    bool isISBNSame(string i) const {
        return ISBN == i;
    }

    void updateStock(int amount) {
        stock += amount;
    }

    void showAuthors() const {
        cout << "Authors: ";
        for (int i = 0; i < numAuthors; i++)
            cout << authors[i] << " ";
        cout << endl;
    }

    void showBookInfo() const {
        cout << "Title: " << title << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        showAuthors();
        cout << "-------------------" << endl;
    }

    // Destructor
    ~bookType() {
        // No dynamic memory used
    }
};

int main() {
    bookType library[100];
    int count = 0;

    string auth1[] = {"Author A", "Author B"};
    library[0].setTitle("C++ Programming");
    library[0].setISBN("123-ABC");
    library[0].setPublisher("TechPress");
    library[0].setPrice(50.0);
    library[0].setStock(10);
    library[0].setAuthors(auth1, 2);
    count++;

    // Search by ISBN
    string searchISBN = "123-ABC";
    for (int i = 0; i < count; i++) {
        if (library[i].isISBNSame(searchISBN)) {
            library[i].updateStock(5);
            library[i].showBookInfo();
        }
    }

    // Search by Title
    string searchTitle = "C++ Programming";
    for (int i = 0; i < count; i++) {
        if (library[i].isTitleSame(searchTitle)) {
            library[i].showBookInfo();
        }
    }

    return 0;
}
