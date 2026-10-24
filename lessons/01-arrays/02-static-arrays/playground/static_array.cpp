// Playground for Lesson 2 — Static Arrays.
// Run target "02-pg-static_array". Change values, add prints, break things on purpose.
#include <cstdint>
#include <iostream>

// Remove the element at index i by shifting everything after it one slot left. O(n).
void removeAt(int arr[], int& length, int i) {
    for (int k = i + 1; k < length; k++) {
        arr[k - 1] = arr[k];
    }
    length--;
}

// Insert value at index i by shifting from the end one slot right. O(n).
// Assumes length < capacity.
void insertAt(int arr[], int& length, int i, int value) {
    for (int k = length - 1; k >= i; k--) {
        arr[k + 1] = arr[k];
    }
    arr[i] = value;
    length++;
}

void print(const char* label, const int arr[], int length, int capacity) {
    std::cout << label << " [";
    for (int k = 0; k < capacity; k++) {
        if (k > 0) {
            std::cout << ", ";
        }
        if (k < length) {
            std::cout << arr[k];
        } else {
            std::cout << '_';  // unused slot
        }
    }
    std::cout << "]  length=" << length << " capacity=" << capacity << '\n';
}

int main() {
    constexpr int kCapacity = 6;
    int arr[kCapacity] = {4, 5, 6};  // remaining slots are zero-initialized
    int length = 3;

    // 1. Contiguous memory: address(arr[i]) = address(arr[0]) + i * sizeof(int)
    std::cout << "sizeof(int) = " << sizeof(int) << " bytes\n";
    const auto base = reinterpret_cast<std::uintptr_t>(&arr[0]);
    for (int i = 0; i < length; i++) {
        const auto address = reinterpret_cast<std::uintptr_t>(&arr[i]);
        std::cout << "&arr[" << i << "] = " << &arr[i] << "  (base + " << address - base << ")\n";
    }
    std::cout << '\n';

    // 2. Insert / remove in the middle.
    print("start          ", arr, length, kCapacity);

    insertAt(arr, length, 1, 8);
    print("insertAt(1, 8) ", arr, length, kCapacity);

    insertAt(arr, length, 0, 1);
    print("insertAt(0, 1) ", arr, length, kCapacity);

    removeAt(arr, length, 2);
    print("removeAt(2)    ", arr, length, kCapacity);

    removeAt(arr, length, 1);
    print("removeAt(1)    ", arr, length, kCapacity);
}
