#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* dataArray;
    size_t currentCount;
    size_t maxCapacity;

    void resize(size_t newCapacity);

public:
    DynamicArray(size_t initialCapacity = 5);
    ~DynamicArray();

    // Prevent unsafe copying (Rule of Three)
    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    void addItem(int val);
    void removeItemAt(int idx);
    int findItem(int target) const;
    void printAll() const;

    size_t getCount() const { return currentCount; }
    size_t getCapacity() const { return maxCapacity; }
};

#endif // DYNAMIC_ARRAY_H
