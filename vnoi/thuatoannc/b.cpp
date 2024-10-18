#include<bits/stdc++.h>
using namespace std;

const int MAX_DIGITS = 20;
int dp[MAX_DIGITS][2][2][2];

// Chuyển số x thành mảng chữ số
vector<int> toDigits(long long x) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

// Hàm quy hoạch động để đếm số chẵn lẻ từ 1 đến limit
int countEvenOddNumbers(const vector<int>& digits, int pos = 0, int tight = 1, int even_odd = -1, int started = 0) {
    // Cơ sở: nếu duyệt hết các chữ số thì trả về 1 (có 1 số hợp lệ)
    if (pos == digits.size()) {
        return 1;
    }
    
    // Kiểm tra nếu trạng thái đã được tính trước đó
    if (dp[pos][tight][even_odd + 1][started] != -1) {
        return dp[pos][tight][even_odd + 1][started];
    }

    int limit = tight ? digits[pos] : 9;  // Nếu tight == 1 thì số phải <= chữ số hiện tại, ngược lại thì có thể là bất kỳ từ 0 đến 9
    int result = 0;

    // Duyệt qua tất cả các chữ số có thể từ 0 đến limit
    for (int d = 0; d <= limit; ++d) {
        // Nếu chưa bắt đầu (tức là chưa có chữ số nào), ta có thể bắt đầu từ bất kỳ chữ số nào lớn hơn 0
        if (!started) {
            result += countEvenOddNumbers(digits, pos + 1, tight && (d == limit), -1, d > 0);
        } else {
            // Nếu đã bắt đầu thì kiểm tra điều kiện chẵn lẻ
            if (even_odd == -1 || (d % 2) != even_odd) {  // Đảm bảo rằng hai chữ số liên tiếp không cùng chẵn hoặc cùng lẻ
                result += countEvenOddNumbers(digits, pos + 1, tight && (d == limit), d % 2, 1);
            }
        }
    }

    // Lưu lại kết quả đã tính để tránh tính lại lần sau
    return dp[pos][tight][even_odd + 1][started] = result;
}

// Hàm đếm số chẵn lẻ từ 1 đến x
int countEvenOddNumbersInRange(long long x) {
    if (x < 1) return 0;
    vector<int> digits = toDigits(x);
    memset(dp, -1, sizeof(dp));  // Xóa bảng nhớ
    return countEvenOddNumbers(digits);
}

int main() {
    long long a, b;
    cin >> a >> b;

    // Đếm số chẵn lẻ từ 1 đến b và từ 1 đến a-1
    int result = countEvenOddNumbersInRange(b) - countEvenOddNumbersInRange(a - 1);

    // In ra kết quả
    cout << result << endl;

    return 0;
}
