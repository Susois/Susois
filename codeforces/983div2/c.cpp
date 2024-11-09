#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra nếu bộ ba phần tử tạo thành tam giác không suy biến
bool is_triangle(int x, int y, int z) {
    return x + y > z && y + z > x && z + x > y;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    // Đọc mảng đầu vào
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Nếu mảng có đúng 3 phần tử, kiểm tra trực tiếp bất đẳng thức tam giác
    if (n == 3) {
        if (is_triangle(a[0], a[1], a[2])) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
        return;
    }

    // Đếm tần suất của từng phần tử trong mảng
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    // Tìm tần suất lớn nhất (số lần xuất hiện của giá trị phổ biến nhất)
    int max_freq = 0;
    for (const auto& entry : freq) {
        max_freq = max(max_freq, entry.second);
    }

    // Số phép biến đổi tối thiểu sẽ là n - số phần tử phổ biến nhất
    cout << (n - max_freq) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
