#include<bits/stdc++.h>
using namespace std;

// Hàm chuyển một số N thành mảng các chữ số
vector<int> getDigits(int n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

int main() {
    int N;
    cin >> N;

    // Mảng dp để lưu trữ trạng thái thắng/thua
    vector<int> dp(N + 1, 0);

    // dp[0] = 0, nếu N = 0 thì người chơi hiện tại thua
    dp[0] = 0;

    // Xét các trạng thái từ 1 đến N
    for (int i = 1; i <= N; i++) {
        vector<int> digits = getDigits(i);
        for (int d : digits) {
            if (d > 0 && dp[i - d] == 0) {
                dp[i] = 1;
                break;
            }
        }
    }

    // Nếu dp[N] == 1 thì Hải thắng, ngược lại Linh thắng
    if (dp[N] == 1) {
        cout << "Hai" << endl;
    } else {
        cout << "Linh" << endl;
    }

    return 0;
}
