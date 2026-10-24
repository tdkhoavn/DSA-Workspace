# Vòng lặp range-based `for`

```cpp
for (const int num : nums) {
    // num lần lượt là từng phần tử của nums
}
```

Đọc là: "với mỗi `num` trong `nums`".

## Khi nào dùng?

- Khi chỉ cần **giá trị** từng phần tử, không cần **chỉ số** `i` → dùng range-based `for`.
- Khi cần chỉ số (so sánh `nums[i]` với `nums[i - 1]`, ghi vào vị trí `i`…) → dùng `for` có chỉ số.

Ưu điểm: không thể truy cập ngoài mảng, không lẫn `int` với `std::size_t`, đọc gọn hơn.

## Ba biến thể

| Cách viết | Ý nghĩa | Dùng khi |
|---|---|---|
| `for (int x : v)` | `x` là **bản sao** | phần tử nhỏ (`int`, `char`…) |
| `for (const int x : v)` | bản sao, không được gán lại | như trên, muốn chắc không sửa nhầm |
| `for (const auto& x : v)` | **tham chiếu** chỉ đọc, không copy | phần tử lớn (`std::string`, `std::vector`…) |
| `for (auto& x : v)` | tham chiếu, **sửa được phần tử gốc** | muốn thay đổi chính mảng |

```cpp
std::vector<int> v = {1, 2, 3};
for (int x : v)  { x *= 2; }   // v vẫn là {1, 2, 3} — chỉ sửa bản sao
for (auto& x : v) { x *= 2; }  // v thành {2, 4, 6}
```

## Gặp ở

- [Max Consecutive Ones](../lessons/01-arrays/02-static-arrays/max-consecutive-ones/solution.hpp)
