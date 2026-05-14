#include <iostream>
using namespace std;

class Array2D {
    int rows, cols;
    int** data;

public:
    Array2D(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols];
    }

    void input() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    bool search(int target) {
        int left = 0, right = rows * cols - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            int r = mid / cols;
            int c = mid % cols;

            if (data[r][c] == target)
                return true;
            else if (data[r][c] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    ~Array2D() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }
};

int main() {
    Array2D A(3,4);

    cout << "Enter matrix:\n";
    A.input();

    int target;
    cout << "Enter target: ";
    cin >> target;

    if (A.search(target))
        cout << "True";
    else
        cout << "False";

    return 0;
}