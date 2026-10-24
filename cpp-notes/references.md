# Tham chiếu (`&`) và `const&` khi truyền tham số

```cpp
void byValue(std::vector<int> v);              // COPY toàn bộ mảng — O(n)
void byRef(std::vector<int>& v);               // không copy, hàm SỬA ĐƯỢC mảng gốc
void byConstRef(const std::vector<int>& v);    // không copy, hàm CHỈ ĐỌC
```

- **Tham chiếu** (`&`) là một tên khác cho chính biến gốc — không tạo bản sao.
- Truyền `std::vector` theo giá trị sẽ copy cả `n` phần tử: tốn thêm O(n) thời gian và O(n) bộ nhớ trước khi hàm kịp làm gì.
- `const&` = không copy **và** cam kết không sửa. Trình biên dịch báo lỗi nếu lỡ tay gán vào.

## Quy tắc chọn

| Hàm cần gì với tham số? | Kiểu nên dùng |
|---|---|
| Kiểu nhỏ (`int`, `double`, `char`, `bool`) | theo giá trị: `int x` |
| Chỉ đọc một đối tượng lớn | `const T&` |
| Sửa đối tượng của người gọi | `T&` |

## Với LeetCode

LeetCode hay cho chữ ký `std::vector<int>& nums` (không có `const`) kể cả khi bài chỉ cần đọc. Đổi thành `const std::vector<int>& nums` vẫn nộp được, và nói rõ hơn ý định của hàm. Bài nào yêu cầu sửa mảng tại chỗ (ví dụ Remove Element) thì phải giữ `&` không `const`.

## Gặp ở

- [Max Consecutive Ones](../lessons/01-arrays/02-static-arrays/max-consecutive-ones/solution.hpp)
