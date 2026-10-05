#include "DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray(size_t initialCapacity)
    : currentCount(0), maxCapacity(initialCapacity) {
    dataArray = new int[maxCapacity];
}

DynamicArray::~DynamicArray() {
    delete[] dataArray; // RAII memory cleanup
    dataArray = nullptr;
}

void DynamicArray::resize(size_t newCapacity) {
    int* temp = new int[newCapacity];
    for (size_t i = 0; i < currentCount; ++i) {
        temp[i] = dataArray[i];
    }
    delete[] dataArray; // Release old heap buffer
    dataArray = temp;
    maxCapacity = newCapacity;
}

void DynamicArray::addItem(int val) {
    if (currentCount >= maxCapacity) {
        resize(maxCapacity * 2);
    }
    dataArray[currentCount++] = val;
    cout << "Added item: " << val << endl;
}

void DynamicArray::removeItemAt(int idx) {
    // Enforce upper and lower bounds checking
    if (idx < 0 || static_cast<size_t>(idx) >= currentCount) {
        cout << "Error: Invalid index " << idx << "!" << endl;
        return;
    }

    // Single-pass O(n) element shifting
    for (size_t i = static_cast<size_t>(idx); i < currentCount - 1; ++i) {
        dataArray[i] = dataArray[i + 1];
    }
    --currentCount;
    cout << "Item removed from index " << idx << endl;
}

int DynamicArray::findItem(int target) const {
    for (size_t i = 0; i < currentCount; ++i) {
        if (dataArray[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void DynamicArray::printAll() const {
    if (currentCount == 0) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "Current List Contents: ";
    for (size_t i = 0; i < currentCount; ++i) { // Strict < check
        cout << dataArray[i] << " ";
    }
    cout << endl;
}
