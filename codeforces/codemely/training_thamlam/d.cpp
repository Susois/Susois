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
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
using namespace std;

void solve() {
    int n, m, k; 
    cin >> n >> m >> k;
    vec h(n);          
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];    
    }

    for (int i = 0; i < n - 1; i++) {
        if (h[i] >= h[i + 1] - k) {
            m += h[i] - max(0, h[i + 1] - k);
        } 
        else {
            int needed = (h[i + 1] - k) - h[i]; 
            if (m >= needed) {
                m -= needed;
            } 
            else {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
