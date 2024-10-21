// #include<bits/stdc++.h>
// #define ll long long
// #define lli int64_t
// #define fi first 
// #define se second
// #define all(x) x.begin(), x.end()
// #define sz(x) (int)x.size()
// #define mp make_pair
// #define pb push_back
// #define vec vector<int> 
// #define pii pair<int,int>
// #define re return
// #define br break
// #define fast                        \
// ios_base::sync_with_stdio(false);   \
// cin.tie(0);cout.tie(0);             
// const int N = 1e5 + 5;
// const int INF = 1e9 + 7;
// const double EPS = 1e-9;
// const double PI = acos(-1.0);
// using namespace std;

// // Hàm tính số thao tác ít nhất
// int min_operations(vector<int>& arr) {
//     int n = arr.size();
//     int operations = 0;
//     int i = 0;

//     while (i < n) {
//         // Tìm đoạn liên tiếp giống nhau bắt đầu từ i
//         int j = i;
//         while (j < n && arr[j] == arr[i]) {
//             j++;
//         }
        
//         // Sau khi đã có đoạn từ i -> j-1, ta cần mở rộng đoạn này để bao phủ các phần còn lại
//         int length = j - i;
//         while (j < n) {
//             operations++;  // mỗi lần sao chép 1 đoạn
//             // Copy đoạn từ j đến j + length (hoặc đến cuối nếu không đủ)
//             int new_j = min(n, j + length);
//             length = new_j - i; // Độ dài mới sau khi mở rộng
//             j = new_j;
//         }

//         // Khi đã bao phủ toàn bộ mảng, ta dừng lại
//         i = j;
//     }

//     return operations;
// }

// int main() {
//     fast
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }
//         cout << min_operations(arr) << endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

// Hàm tính số thao tác ít nhất sử dụng DP
int min_operations(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n + 1, INT_MAX); // dp[i] là số thao tác ít nhất để bao phủ đến vị trí i
    dp[0] = 0; // Không cần thao tác nào để bắt đầu
    
    for (int i = 0; i < n; i++) {
        if (dp[i] == INT_MAX) continue; // Nếu vị trí i không thể bao phủ, bỏ qua

        // Tìm đoạn liên tiếp giống nhau bắt đầu từ i
        int j = i;
        while (j < n && arr[j] == arr[i]) {
            j++;
        }
        
        // Độ dài đoạn liên tiếp giống nhau
        int length = j - i;
        
        // Cập nhật số thao tác để bao phủ từ j đến j + length
        for (int k = j; k <= n; k += length) {
            dp[k] = min(dp[k], dp[i] + 1); // Mỗi lần sao chép đoạn cần 1 thao tác
            length = k - i;  // Độ dài mới sau khi mở rộng
        }
    }

    return dp[n];  // Số thao tác ít nhất để bao phủ toàn bộ mảng
}

int main() {
    fast
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << min_operations(arr) << endl;
    }
    return 0;
}
