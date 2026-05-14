#include <iostream>
using namespace std;

class Character {
private:
    int *health, *attackPower, *defense;

public:
    Character() {
        health = new int(100);
        attackPower = new int(10);
        defense = new int(5);
    }

    Character(int h, int a, int d) {
        health = new int(h);
        attackPower = new int(a);
        defense = new int(d);
    }

    Character(const Character& source) {
        health = new int(*source.health);
        attackPower = new int(*source.attackPower);
        defense = new int(*source.defense);
    }

    ~Character() {
        delete health;
        delete attackPower;
        delete defense;
    }

    void setHealth(int h) { *health = h; }
    void setAttackPower(int a) { *attackPower = a; }
    void setDefense(int d) { *defense = d; }

    int getHealth() const { return *health; }
    int getAttackPower() const { return *attackPower; }
    int getDefense() const { return *defense; }

    void displayStats() const {
        cout << "H: " << *health << " A: " << *attackPower << " D: " << *defense << endl;
    }
};

int main() {
    Character p1;
    Character p2(200, 30, 20);
    Character p3 = p2;
    p3.setHealth(150);
    p1.displayStats();
    p2.displayStats();
    p3.displayStats();
    return 0;
}