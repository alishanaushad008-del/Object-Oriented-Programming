#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void customSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of integers: ";
    cin >> n;

    vector<int> vec1(n);
    vector<int> vec2(n);

    cout << "Enter the integers: ";
    for (int i = 0; i < n; i++) {
        cin >> vec1[i];
        vec2[i] = vec1[i];
    }

    clock_t start1 = clock();
    customSort(vec1);
    clock_t end1 = clock();

    clock_t start2 = clock();
    sort(vec2.begin(), vec2.end());
    clock_t end2 = clock();

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    double time1 = double(end1 - start1) / CLOCKS_PER_SEC;
    double time2 = double(end2 - start2) / CLOCKS_PER_SEC;

    cout << "Time taken by custom sort: " << time1 << " seconds" << endl;
    cout << "Time taken by STL sort: " << time2 << " seconds" << endl;

    return 0;
}