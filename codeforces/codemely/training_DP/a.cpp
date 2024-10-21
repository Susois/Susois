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
#define ll long long
#define lli int64_t
#define fi first 
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define vec vector<int> 
#define pii pair<int,int>
#define re return
#define br break
#define fast                        \
ios_base::sync_with_stdio(false);   \
cin.tie(0);cout.tie(0);             
const int N = 2e5 + 5;  // Tăng kích thước cho phù hợp với n tối đa
using namespace std;

// Hàm tính số thao tác ít nhất
int min_operations(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> freq;  // Đếm tần suất của các phần tử

    // Đếm tần suất của mỗi phần tử
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Tìm tần suất lớn nhất
    int max_freq = 0;
    for (auto& p : freq) {
        max_freq = max(max_freq, p.second);
    }

    // Số thao tác cần thiết là tổng số phần tử trừ đi tần suất lớn nhất
    return n - max_freq;
}

int main() {
    fast
    int t;
    cin >> t;  // Đọc số bộ đề
    while (t--) {
        int n;
        cin >> n;  // Đọc số câu hỏi
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];  // Đọc các câu hỏi
        }
        cout << min_operations(arr) << endl;  // In ra số thao tác tối thiểu
    }
    return 0;
}
