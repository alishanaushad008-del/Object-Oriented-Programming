#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int level;
    int health;

public:
    Character(string n, int l, int h) {
        name = n;
        level = l;
        health = h;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << health << endl;
    }
};

class Warrior : virtual public Character {
protected:
    int strength;
    int meleeProficiency;

public:
    Warrior(string n, int l, int h, int s, int m)
        : Character(n, l, h) {
        strength = s;
        meleeProficiency = m;
    }

    void slash() {
        cout << "Slash attack!" << endl;
    }

    void display() {
        Character::display();
        cout << "Strength: " << strength << endl;
        cout << "Melee Proficiency: " << meleeProficiency << endl;
    }
};

class Mage : virtual public Character {
protected:
    int intelligence;
    int spellProficiency;

public:
    Mage(string n, int l, int h, int i, int sp)
        : Character(n, l, h) {
        intelligence = i;
        spellProficiency = sp;
    }

    void fireball() {
        cout << "Fireball cast!" << endl;
    }

    void display() {
        Character::display();
        cout << "Intelligence: " << intelligence << endl;
        cout << "Spell Proficiency: " << spellProficiency << endl;
    }
};

class Archer : public Character {
protected:
    int dexterity;
    int rangedProficiency;

public:
    Archer(string n, int l, int h, int d, int r)
        : Character(n, l, h) {
        dexterity = d;
        rangedProficiency = r;
    }

    void rapidShot() {
        cout << "Rapid shot!" << endl;
    }

    void display() {
        Character::display();
        cout << "Dexterity: " << dexterity << endl;
        cout << "Ranged Proficiency: " << rangedProficiency << endl;
    }
};

class NPC : public Character {
    string behavior;

public:
    NPC(string n, int l, int h, string b)
        : Character(n, l, h) {
        behavior = b;
    }

    void display() {
        Character::display();
        cout << "Behavior: " << behavior << endl;
    }
};

class Mighty : public Warrior, public Mage {
public:
    Mighty(string n, int l, int h, int s, int m, int i, int sp)
        : Character(n, l, h),
          Warrior(n, l, h, s, m),
          Mage(n, l, h, i, sp) {}

    void display() {
        Character::display();
        cout << "Strength: " << strength << endl;
        cout << "Melee Proficiency: " << meleeProficiency << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Spell Proficiency: " << spellProficiency << endl;
    }
};

int main() {
    Mighty m("Hero", 10, 100, 80, 70, 90, 85);
    m.display();
    m.slash();
    m.fireball();

    return 0;
}