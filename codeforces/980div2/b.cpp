// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const int MOD = 1e9 + 7;
// void solve(){
//     int n,k,cnt=0;cin>>n>>k;
//     vector<int> a(n);
//     for(auto &x:a)cin>>x;
//     sort(a.begin(),a.end(),greater<int>());
//     for(int i=0;i<n;i++){
        
//             if(a[i] > k ){
//                 cnt+=k;
//                 cout<<cnt<<'\n';
//                 return;
//             }
//             else {
//                 cnt+=a[i] +1;
//                 k -= a[i];
//             }
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);cout.tie(0);

//     int t;cin>>t;
//     while(t--){
//     solve();
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    // Sắp xếp số lon nước chanh theo thứ tự giảm dần
    sort(a.begin(), a.end(), greater<int>());

    int presses = 0;  // Số lần nhấn nút
    for (int i = 0; i < n; ++i) {
        if (k <= 0) break; // Nếu đã lấy đủ số lon thì dừng
        // Nếu slot hiện tại có nhiều lon nước chanh hơn số còn lại cần lấy
        if (a[i] <= k) {
            k -= a[i];      // Lấy tất cả lon nước chanh từ slot này
            presses += a[i]; // Số lần nhấn nút tăng thêm đúng bằng số lon đã lấy
        } else {
            presses += k;    // Nếu còn ít hơn, chỉ cần nhấn đúng số lần lấy k lon
            k = 0;           // Đã lấy đủ số lon nước chanh
        }
    }
    cout << presses << '\n'; // Kết quả là số lần nhấn nút
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;  // Đọc số lượng test case
    while (t--) {
        solve();  // Xử lý từng test case
    }

    return 0;
}
