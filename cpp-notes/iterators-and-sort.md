# Iterator và `std::sort`

## Iterator là gì?

Một **iterator** là "con trỏ" chỉ vào một vị trí trong container (`std::vector`, `std::array`, `std::string`…).

```cpp
std::vector<int> v = {5, 3, 8, 1};
//                    ^           ^
//               v.begin()     v.end()   ← end() là ô NGAY SAU phần tử cuối
```

- `v.begin()` — chỉ vào phần tử đầu tiên.
- `v.end()` — chỉ vào **sau** phần tử cuối (không phải phần tử cuối!). Không được đọc `*v.end()`.
- `v.begin() + k` — chỉ vào phần tử thứ `k` (vector cho phép nhảy thẳng, O(1) — giống công thức địa chỉ của static array).
- `*it` — lấy giá trị tại vị trí `it`.

## Khoảng nửa mở `[first, last)`

Hầu hết thuật toán của thư viện chuẩn nhận **hai iterator** `first, last` và làm việc trên khoảng **`[first, last)`**: lấy `first`, **không** lấy `last`.

```cpp
v.begin(), v.end()        // cả vector
v.begin(), v.begin() + k  // k phần tử đầu: index 0 … k-1
```

Lợi ích: số phần tử luôn là `last - first`, và khoảng rỗng là khi `first == last` — không cần xử lý riêng.

## `std::sort` (header `<algorithm>`)

```cpp
#include <algorithm>

std::sort(v.begin(), v.end());              // sắp xếp cả vector, tăng dần
std::sort(v.begin(), v.begin() + k);        // chỉ sắp xếp k phần tử đầu
std::sort(v.begin(), v.end(), std::greater<int>());  // giảm dần
```

- Độ phức tạp **O(n log n)**. Thuật toán bên trong sẽ học ở các lesson Sorting (10–13).
- Sắp xếp **tại chỗ** (in-place) — sửa trực tiếp container.

## Tạo vector con từ một khoảng

```cpp
std::vector<int> firstK(v.begin(), v.begin() + k);  // copy k phần tử đầu sang vector mới
```

## Gặp ở

- [Remove Element — test helper `expectRemoved`](../lessons/01-arrays/02-static-arrays/remove-element/solution_test.cpp)
