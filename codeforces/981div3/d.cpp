// #include<bits/stdc++.h>
// #define ll long long
// #define lli int64_t
// #define fi first 
// #define se second
// #define sz(x) (int)x.size()
// #define all(x) x.begin(), x.end()
// #define fint(i,x) for(int i=1;i<=x;i++)
// #define fstr(i,s) for(int i=0;i<sz(s);i++)
// #define mp make_pair
// #define pb push_back
// #define vec vector<int> 
// #define pii pair<int,int>
// #define re return
// #define br break
// #define fast                        \
// ios_base::sync_with_stdio(false);   \
// cin.tie(0);cout.tie(0);             \
// const int N = 1e5 + 5;
// const int INF = 1e9 + 7;
// const double EPS = 1e-9;
// const double PI = acos(-1.0);


// using namespace std;


// void solve(){
//     int n,cnt=0,k=0;cin>>n;
//     vector<int> se(n+1);
//     fint(i,n)cin>>se[i];
//     int pre[n+1];
//     memset(pre,0,sizeof(pre));
//     fint(i,n)pre[i] = pre[i-1] + se[i];
//     fint(i,n){
//         if(se[i]==0){
//             cnt++;
//             k=i;
//             continue;
//         }
//         else {
//             for(int j=k;j<=i;j++){
//                 if(pre[i] - pre[j-1]==0){
//                     cnt++;
//                     k=i+1;
//                     break;
//                 }
//             }
//         }
//     }
//     cout<<cnt;
// }
// int main(){
//     fast

//     int t;cin>>t;
//     while(t--){
//     solve();
//     cout<<'\n';
//     }
//     return 0;
// }
#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    
    // Đọc input
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> prefix_sum_map;
    prefix_sum_map[0] = 0; // tổng bằng 0 ở trước vị trí đầu tiên
    int current_sum = 0;
    int last_index = 0; // vị trí cuối của đoạn con không chồng lấn
    int cnt = 0; // số đoạn con có tổng bằng 0

    for (int i = 1; i <= n; i++) {
        current_sum += a[i];

        // Nếu tổng tích lũy đã gặp trước đó, nghĩa là có đoạn con có tổng bằng 0
        if (prefix_sum_map.count(current_sum)) {
            // Đảm bảo đoạn không chồng lấn
            last_index = max(last_index, prefix_sum_map[current_sum] + 1);
            cnt++; // đếm một đoạn con mới
            current_sum = 0; // reset tổng tích lũy
            prefix_sum_map.clear(); // bắt đầu lại
            prefix_sum_map[0] = i; // tổng bằng 0 từ vị trí hiện tại
        } else {
            prefix_sum_map[current_sum] = i;
        }
    }

    cout << cnt << '\n';
}

int main() {
    fast
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
