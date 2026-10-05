#include <iostream>
#include "DynamicArray.h"
using namespace std;

void processMatrixDynamic(int rows, int cols) {
    int m[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int t[3][3];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            t[j][i] = m[i][j];
        }
    }

    cout << "Transposed Matrix printed raw:" << endl;
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "--- STARTING REFACTORED SUBSYSTEM ---" << endl;

    DynamicArray list;

    list.addItem(10);
    list.addItem(20);
    list.addItem(30);
    list.addItem(40);
    list.addItem(50);
    list.addItem(60); // Triggers clean dynamic resize

    list.printAll();

    cout << "Found 30 at index: " << list.findItem(30) << endl;

    list.removeItemAt(2);
    list.printAll();

    list.removeItemAt(99); // Rejected safely by bounds check
    list.printAll();

    processMatrixDynamic(3, 3);

    return 0; // ~DynamicArray() automatically releases heap memory
}
