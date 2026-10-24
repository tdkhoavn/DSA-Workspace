# Lesson 2 — Static Arrays

> https://neetcode.io/courses/dsa-for-beginners/2

## Ý chính

- **Array** là một khối bộ nhớ **liền kề** (_contiguous_): các phần tử nằm sát nhau trong RAM, không có khoảng trống, và mọi phần tử có cùng kiểu, cùng kích thước.
- **Static array** là array có **số lượng phần tử (capacity) cố định** ngay khi khai báo. Đầy rồi thì không thêm được nữa. Muốn có chỗ lớn hơn phải cấp phát mảng mới — đó là chủ đề của lesson Dynamic Arrays.
- Truy cập bằng **index**, bắt đầu từ `0`. Phần tử cuối cùng nằm ở index `n - 1` (với `n` là số phần tử).
- Đọc / ghi theo index là **O(1)** vì địa chỉ của phần tử thứ `i` tính được ngay bằng công thức:

  ```
  address(arr[i]) = address(arr[0]) + i × sizeof(element)
  ```

  Một phép nhân + một phép cộng, không phụ thuộc mảng dài bao nhiêu.
- **O(1) không có nghĩa là "nhanh"**, mà là _số bước không tăng khi dữ liệu tăng_. 1000 bước cố định vẫn là O(1).
- Duyệt toàn bộ mảng bằng `for` / `while` là **O(n)**: mảng dài gấp đôi thì số bước gấp đôi.

### `length` và `capacity`

- `capacity`: số ô đã cấp phát — cố định với static array.
- `length`: số phần tử **thực sự đang dùng** — ta tự theo dõi bằng một biến riêng.
- Ô "trống" là các index từ `length` đến `capacity - 1`.

## Các thao tác và độ phức tạp

| Thao tác | Độ phức tạp | Vì sao? |
|---|---|---|
| Đọc / ghi phần tử thứ `i` | O(1) | Tính thẳng địa chỉ từ index |
| Duyệt toàn bộ | O(n) | Phải ghé từng phần tử một |
| Chèn ở cuối | O(1) | Ghi vào `arr[length]` rồi `length++` (nếu `length < capacity`) |
| Xóa ở cuối | O(1) | _Soft delete_: ghi đè bằng giá trị "rỗng" (0, -1…) rồi `length--` |
| Chèn ở giữa (index `i`) | O(n) | Phải dời các phần tử từ `i` trở đi sang **phải** 1 ô |
| Xóa ở giữa (index `i`) | O(n) | Phải dời các phần tử sau `i` sang **trái** 1 ô để không để lại lỗ hổng |

Trường hợp xấu nhất của chèn/xóa ở giữa là `i = 0`: phải dời toàn bộ `n` phần tử.

### Chèn ở giữa: vì sao phải dời **từ cuối về**?

Chèn `8` vào index `1` của `[4, 5, 6, _]`:

```
Dời từ cuối về (đúng):          Dời từ i trở đi (sai):
[4, 5, 6, 6]  arr[3] = arr[2]   [4, 5, 5, _]  arr[2] = arr[1]  ← 6 bị ghi đè, mất!
[4, 5, 5, 6]  arr[2] = arr[1]
[4, 8, 5, 6]  arr[1] = 8
```

Xóa thì ngược lại: dời sang trái, đi **từ `i + 1` lên cuối**.

```cpp
// Xóa phần tử ở index i — O(n)
void removeAt(int arr[], int& length, int i) {
    for (int k = i + 1; k < length; k++) {
        arr[k - 1] = arr[k];
    }
    length--;
}

// Chèn value vào index i — O(n), giả sử length < capacity
void insertAt(int arr[], int& length, int i, int value) {
    for (int k = length - 1; k >= i; k--) {
        arr[k + 1] = arr[k];
    }
    arr[i] = value;
    length++;
}
```

> 💡 Rất nhiều bài phỏng vấn về array thực chất là: làm thao tác chèn/xóa ở giữa **mà không tốn O(n) mỗi lần** — ví dụ dùng hai con trỏ để dời phần tử một lượt duy nhất.

## Riêng với C++

- Mảng kiểu C: `int arr[5];` — kích thước phải là hằng số lúc biên dịch.
- ⚠️ Khác với Java/C#, mảng cục bộ **không** tự khởi tạo bằng 0, mà chứa giá trị rác. Muốn toàn 0 thì viết `int arr[5] = {};`.
- ⚠️ C++ **không kiểm tra** index vượt giới hạn: `arr[10]` với mảng 5 phần tử là _undefined behavior_ — chương trình có thể chạy "bình thường" rồi sai ở chỗ khác. Repo này bật AddressSanitizer để bắt lỗi đó trong test.
- Xem thêm: [cpp-notes/arrays.md](../../../cpp-notes/arrays.md).

## Playground

[playground/static_array.cpp](playground/static_array.cpp) — chạy target `02-pg-static_array` trong CLion để:
- in địa chỉ từng phần tử và tự kiểm chứng công thức địa chỉ ở trên;
- chạy `insertAt` / `removeAt` và xem mảng thay đổi qua từng bước.
