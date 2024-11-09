// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//     long long n, k;
//     cin >> n >> k;

//     if ( n%2==0 || k>n || k != (n / 2) + 1) {
//         cout << -1;
//         return;
//     }

//         cout<<n<<'\n';
//         for(long long i=1;i<=n;i++){
//             cout<<i<<" ";
//         }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     long long t;
//     cin >> t;
//     while (t--) {
//         solve();
//         cout << '\n';
//     }

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if (n == 1 && k == 1) cout << "1\n1\n"; 
    else if (k == 1 || k == n) cout << -1 << '\n';
    else {
        if (k % 2 == 0) {
            cout << 3 << '\n';
            cout << 1 << ' ' << k << ' ' << k+1 << '\n'; 
        } else  {
            cout << 5 << '\n';
            cout << 1 << ' ' << k - 1 << ' ' << k << ' ' << k + 1 << ' ' << k + 2 << '\n'; 
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}