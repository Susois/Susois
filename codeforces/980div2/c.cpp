// #include<bits/stdc++.h>
// using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     vector<pair<int, int>> arrays(n);
    
//     // Đọc các mảng và chuẩn hóa mỗi mảng
//     for (int i = 0; i < n; ++i) {
//         int x, y;
//         cin >> x >> y;
//         if (x > y) swap(x, y);  // Đảm bảo x <= y
//         arrays[i] = {x, y};
//     }
    
//     // Sắp xếp các mảng theo phần tử đầu tiên
//     sort(arrays.begin(), arrays.end());
    
//     // In ra kết quả
//     for (int i = 0; i < n; ++i) {
//         cout << arrays[i].first << " " << arrays[i].second << " ";
//     }
//     cout << "\n";
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     int t;
//     cin >> t;  // Đọc số lượng test case
//     while (t--) {
//         solve();
//     }
    
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> arrays(n);

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        arrays[i] = make_pair(min(a, b), max(a, b)); // Ensuring first is always <= second
    }

    sort(arrays.begin(), arrays.end()); // Sorting by the first elements

    for (int i = 0; i < n; ++i) {
        cout << arrays[i].first << " " << arrays[i].second << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
