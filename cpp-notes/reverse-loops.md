# Duyệt ngược mảng và bẫy `std::size_t`

`std::size_t` (kiểu của `v.size()`) là số **không dấu**: không bao giờ âm. Trừ 1 từ `0` không ra `-1` mà **quay vòng** thành số lớn nhất của kiểu (khoảng 1,8 × 10¹⁹).

```cpp
for (std::size_t i = v.size() - 1; i >= 0; i--)   // ❌ i >= 0 luôn đúng → lặp vô hạn, đọc ngoài mảng
```

Còn một bẫy nữa: nếu `v` rỗng thì `v.size() - 1` đã quay vòng ngay từ đầu.

## Hai cách đúng

```cpp
// 1. Dùng int — dễ đọc nhất
for (int i = static_cast<int>(v.size()) - 1; i >= 0; i--) { ... v[i] ... }

// 2. Giữ size_t, giảm TRƯỚC khi dùng
for (std::size_t i = v.size(); i-- > 0;) { ... v[i] ... }
```

Cách 2 đọc là "còn `i > 0` không? Có thì giảm `i` rồi vào thân vòng lặp". Lần lượt vào thân với `i = n-1, …, 1, 0`, rồi dừng khi kiểm tra `0 > 0` (sai). Mảng rỗng cũng an toàn: `0 > 0` sai ngay, không vào lần nào.

ASan/UBSan (bật sẵn ở bản Debug) sẽ báo ngay nếu vòng lặp đọc ngoài mảng.

## Gặp ở

- [Replace Elements With Greatest Element On Right Side](../lessons/01-arrays/02-static-arrays/replace-elements-with-greatest-element-on-right-side/solution.hpp): dùng cách 2
