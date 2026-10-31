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

## Giá trị tạm và `T&`

```cpp
s.replaceElements({2, 4, 5});        // ❌ lỗi biên dịch: tham số là std::vector<int>&
std::vector<int> arr = {2, 4, 5};
s.replaceElements(arr);              // ✅ có biến thật để gắn tham chiếu vào
```

`{2, 4, 5}` là **giá trị tạm**, mất ngay sau câu lệnh. `T&` (không `const`) cho phép sửa, nên C++ không cho nó gắn vào thứ sắp biến mất. `const T&` và tham số theo giá trị (`T`) thì nhận giá trị tạm bình thường. Vì vậy hàm trợ giúp trong test hay nhận `std::vector<int> arr` theo giá trị: gọi thẳng với `{...}` được, và bên trong vẫn có một biến thật để truyền tiếp vào `T&`.

## `return` một tham chiếu thì có copy

```cpp
std::vector<int> f(std::vector<int>& arr) {
    return arr;   // COPY n phần tử: arr là dữ liệu của người gọi, không được "lấy" đi
}
```

Trả về **biến cục bộ** (`return result;`) thì C++ chuyển (move) hoặc bỏ hẳn bước copy, gần như miễn phí. Trả về **tham chiếu tới dữ liệu người khác** thì bắt buộc copy. Khi tính Space, bản copy này là đầu ra bắt buộc nên không tính vào bộ nhớ phụ.

## Gặp ở

- [Max Consecutive Ones](../lessons/01-arrays/02-static-arrays/max-consecutive-ones/solution.hpp)
- [Replace Elements With Greatest Element On Right Side](../lessons/01-arrays/02-static-arrays/replace-elements-with-greatest-element-on-right-side/solution_test.cpp): giá trị tạm, `return arr`
