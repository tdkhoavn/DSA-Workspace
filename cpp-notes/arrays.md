# Mảng tĩnh trong C++: C array và `std::array`

## C array

```cpp
int a[5];            // 5 int, giá trị RÁC nếu là biến cục bộ
int b[5] = {};       // 5 số 0
int c[] = {1, 3, 5}; // trình biên dịch tự đếm: kích thước 3
```

- Kích thước phải biết lúc biên dịch.
- Không tự biết độ dài của mình. Khi truyền vào hàm, `int arr[]` thực chất chỉ là con trỏ `int*` → phải truyền thêm `length`.
- Không kiểm tra biên: `a[7]` là _undefined behavior_.

## `std::array` (header `<array>`)

```cpp
#include <array>

std::array<int, 5> a{};   // 5 số 0
a.size();                 // 5 — biết độ dài của mình
a[2] = 7;                 // không kiểm tra biên (nhanh)
a.at(9);                  // CÓ kiểm tra biên → ném std::out_of_range
```

- Vẫn là static array: kích thước cố định, nằm liền kề trong bộ nhớ, chi phí bằng C array.
- Truyền vào hàm không bị "mất" kích thước, copy/so sánh được bằng `=` / `==`.
- **Ưu tiên `std::array` hơn C array** khi viết C++ hiện đại.

## Còn `std::vector`?

`std::vector` là **dynamic array** — sẽ học ở lesson 3. Các bài LeetCode trong C++ hầu hết nhận `std::vector<int>&`, nên ta sẽ dùng nó ngay từ bài đầu tiên.

## Gặp ở

- [Lesson 2 — Static Arrays](../lessons/01-arrays/02-static-arrays/NOTES.md)
