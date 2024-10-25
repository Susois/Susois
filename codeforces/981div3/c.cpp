// // // #include <bits/stdc++.h>
// // // using namespace std;

// // // int minimizeDisturbance(vector<int>& a, int n) {
// // //     int disturbance = 0;
// // //     for (int i = 0; i < n - 1; ++i) {
// // //         if (a[i] == a[i + 1] && a[i != a[n-i-1]]) {
// // //             disturbance++;
// // //         }
// // //     }
// // //     return disturbance;
// // // }

// // // void solve() {
// // //     int t;
// // //     cin >> t;
// // //     while (t--) {
// // //         int n;
// // //         cin >> n;
// // //         vector<int> a(n);
// // //         for (int i = 0; i < n; ++i) {
// // //             cin >> a[i];
// // //         }

// // //         int minDisturbance = minimizeDisturbance(a, n);

// // //         for (int i = 0; i < n / 2; ++i) {
// // //             swap(a[i], a[n - i - 1]);
// // //             minDisturbance = min(minDisturbance, minimizeDisturbance(a, n));
// // //             swap(a[i], a[n - i - 1]);  // swap back to original
// // //         }

// // //         cout << minDisturbance << '\n';
// // //     }
// // // }

// // // int main() {
// // //     ios_base::sync_with_stdio(false);
// // //     cin.tie(0);
// // //     solve();
// // //     return 0;
// // // }

// // #include <bits/stdc++.h>
// // using namespace std;

// // int minimizeDisturbance(const vector<int>& a, int n) {
// //     int disturbance = 0;
// //     for (int i = 0; i < n - 1; ++i) {
// //         if (a[i] == a[i + 1]) {
// //             disturbance++;
// //         }
// //     }
// //     return disturbance;
// // }

// // void solve() {
// //     int t;
// //     cin >> t;
// //     while (t--) {
// //         int n;
// //         cin >> n;
// //         vector<int> a(n);
// //         for (int i = 0; i < n; ++i) {
// //             cin >> a[i];
// //         }

// //         // Xử lý cận dưới: Nếu n = 2
// //         if (n == 2) {
// //             cout << (a[0] == a[1] ? 1 : 0) << '\n';
// //             continue;
// //         }

// //         // Ban đầu tính disturbance hiện tại
// //         int minDisturbance = minimizeDisturbance(a, n);

// //         // Nếu disturbance <= 1, không cần hoán đổi
// //         if (minDisturbance <= 1) {
// //             cout << minDisturbance << '\n';
// //             continue;
// //         }

// //         // Tìm vị trí đầu tiên và cuối cùng có disturbance
// //         int first = -1, last = -1;
// //         for (int i = 0; i < n - 1; ++i) {
// //             if (a[i] == a[i + 1]) {
// //                 if (first == -1) first = i;
// //                 last = i;
// //             }
// //         }

// //         // Xử lý cận trên: Nếu n lớn và có nhiều disturbance
// //         // Nếu khoảng cách giữa first và last disturbance <= 2 thì 1 hoán đổi là đủ, ngược lại cần 2
// //         if (last - first <= 2) {
// //             cout << 1 << '\n';
// //         } else {
// //             cout << 2 << '\n';
// //         }
// //     }
// // }

// // int main() {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(0);
// //     solve();
// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// // Function to count the number of disturbances in the array
// int countDisturbances(const vector<int>& a) {
//     int disturbance = 0;
//     for (int i = 1; i < a.size(); ++i) {
//         if (a[i] == a[i - 1]) {
//             disturbance++;
//         }
//     }
//     return disturbance;
// }

// // Function to solve the problem
// void solve() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }

//         int minDisturbance = countDisturbances(a);

//         // Try swapping elements to find the minimum disturbance
//         for (int i = 0; i < n / 2; ++i) {
//             swap(a[i], a[n - i - 1]);
//             minDisturbance = min(minDisturbance, countDisturbances(a));
//             swap(a[i], a[n - i - 1]);  // Swap back to original
//         }

//         cout << minDisturbance << '\n';
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// Function to count the number of disturbances in the array
int countDisturbances(const vector<int>& a) {
    int disturbance = 0;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i - 1]) {
            disturbance++;
        }
    }
    return disturbance;
}

// Fenwick Tree (Binary Indexed Tree) to manage inversion count
class FenwickTree {
public:
    vector<int> tree;
    int n;

    FenwickTree(int size) : n(size) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int value) {
        for (; index <= n; index += index & -index) {
            tree[index] += value;
        }
    }

    int query(int index) const {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum += tree[index];
        }
        return sum;
    }

    int queryRange(int left, int right) const {
        return query(right) - query(left - 1);
    }
};

// Function to solve the problem
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int minDisturbance = countDisturbances(a);

        // Try swapping elements to find the minimum disturbance
        for (int i = 0; i < n / 2; ++i) {
            swap(a[i], a[n - i - 1]);
            minDisturbance = min(minDisturbance, countDisturbances(a));
            swap(a[i], a[n - i - 1]);  // Swap back to original
        }

        cout << minDisturbance << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
