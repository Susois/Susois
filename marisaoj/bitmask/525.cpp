#include <bits/stdc++.h>
using namespace std;

// Hàm để đếm số lượng bit bật của một số
int countSetBits(int num) {
    return __builtin_popcount(num);
}

int turnOffMostSignificantBit(int num) {
    if (num == 0) return 0;
    int msb = 1 << (31 - __builtin_clz(num)); // Tìm bit bật quan trọng nhất
    return num - msb;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    int a = 0;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            a ^= x;
        } else if (type == 2) {
            a = turnOffMostSignificantBit(a); // Tắt bit bật quan trọng nhất của a
        } else if (type == 3) {
            cout << countSetBits(a) << "\n"; // Đếm số lượng bit bật của a
        }
    }

    return 0;
}
