
#include <iostream>
using namespace std;

class Store {
protected:
    float total_bill;

public:
    Store(float bill) {
        total_bill = bill;
    }

    virtual void calculateBill() = 0;
};

class ImtiazStore : public Store {
public:
    ImtiazStore(float bill) : Store(bill) {}

    void calculateBill() {
        float discount = total_bill * 0.07;
        float final_bill = total_bill - discount;

        cout << "ImtiazStore Final Bill = " << final_bill << endl;
    }
};

class BinHashimStore : public Store {
public:
    BinHashimStore(float bill) : Store(bill) {}

    void calculateBill() {
        float discount = total_bill * 0.05;
        float final_bill = total_bill - discount;

        cout << "BinHashimStore Final Bill = " << final_bill << endl;
    }
};

int main() {
    float bill;

    cout << "Enter Total Bill: ";
    cin >> bill;

    ImtiazStore obj1(bill);
    BinHashimStore obj2(bill);

    obj1.calculateBill();
    obj2.calculateBill();

    return 0;
}