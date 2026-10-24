// Playground for Lesson 2 — Static Arrays.
// Proves address(arr[i]) = address(arr[0]) + i * sizeof(element), three ways.
// Run target "02-pg-address_formula".
#include <cstddef>
#include <iostream>

int main() {
    int arr[4] = {10, 20, 30, 40};
    const std::size_t i = 2;

    // Way 1: what the compiler does for arr[i].
    // arr[i] is defined as *(arr + i). "arr + i" is pointer arithmetic:
    // adding i to an int* moves it forward i * sizeof(int) bytes, not i bytes.
    int* p = arr + i;
    std::cout << "arr[i]       = " << arr[i] << '\n';
    std::cout << "*(arr + i)   = " << *p << '\n';

    // Way 2: do the formula by hand, counting bytes.
    // A char is 1 byte, so a char* moves exactly 1 byte per +1.
    const char* base = reinterpret_cast<const char*>(&arr[0]);   // address(arr[0])
    const char* byHand = base + i * sizeof(int);                  // + i * sizeof(element)
    const int* q = reinterpret_cast<const int*>(byHand);
    std::cout << "by hand      = " << *q << '\n';

    // Way 3: compare the actual addresses.
    std::cout << "&arr[i]      = " << static_cast<const void*>(&arr[i]) << '\n';
    std::cout << "formula      = " << static_cast<const void*>(byHand) << '\n';
    std::cout << "same address? " << std::boolalpha << (byHand == reinterpret_cast<const char*>(&arr[i]))
              << '\n';

    // The cost never depends on the array size: one multiply + one add, whatever i is.
    // That is why reading arr[i] is O(1).
}
