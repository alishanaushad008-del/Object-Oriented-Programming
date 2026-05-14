#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    bool isBorrowed;

public:
    Media(string t) {
        title = t;
        isBorrowed = false;
    }

    void borrowMedia() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << title << " borrowed\n";
        } else {
            cout << title << " already borrowed\n";
        }
    }

    void returnMedia() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << title << " returned\n";
        } else {
            cout << title << " was not borrowed\n";
        }
    }

    virtual void display() const {
        cout << "Title: " << title << endl;
        cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

class BookDetails {
protected:
    string author;

public:
    BookDetails(string a) {
        author = a;
    }
};

class MagazineDetails {
protected:
    int issueNumber;

public:
    MagazineDetails(int i) {
        issueNumber = i;
    }
};

class DVDDetails {
protected:
    string director;

public:
    DVDDetails(string d) {
        director = d;
    }
};

class Book : public Media, public BookDetails {
public:
    Book(string t, string a) : Media(t), BookDetails(a) {}

    void display() const override {
        Media::display();
        cout << "Author: " << author << endl;
    }
};

class Magazine : public Media, public MagazineDetails {
public:
    Magazine(string t, int i) : Media(t), MagazineDetails(i) {}

    void display() const override {
        Media::display();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

class DVD : public Media, public DVDDetails {
public:
    DVD(string t, string d) : Media(t), DVDDetails(d) {}

    void display() const override {
        Media::display();
        cout << "Director: " << director << endl;
    }
};

int main() {
    Book b("1984", "George Orwell");
    Magazine m("Time", 542);
    DVD d("Matrix", "Wachowski");

    b.display();
    cout << endl;

    b.borrowMedia();
    b.display();
    cout << endl;

    m.display();
    m.borrowMedia();
    m.returnMedia();
    cout << endl;

    d.display();

    return 0;
}