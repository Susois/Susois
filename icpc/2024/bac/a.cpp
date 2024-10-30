#include <bits/stdc++.h>
#define ll long long
#define lli int64_t
#define fi first 
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fint(i, x) for(int i = 1; i <= x; i++)
#define fstr(i, s) for(int i = 0; i < sz(s); i++)
#define mp make_pair
#define pb push_back
#define vec vector<int> 
#define pii pair<int, int>
#define re return
#define br break
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

void solve() {
    int n, D, H; 
    cin >> n >> D >> H;
    vector<int> h(n);
    vector<int> dp(n, INF); 
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    dp[0] = h[0];  
    for(int i = 1; i < n; i++) {
        for(int j = max(0, i - D); j < i; j++) {
            if(abs(h[i] - h[j]) <= H) { 
                dp[i] = min(dp[i], dp[j] + h[i]);
            }
        }
    }
    if (dp[n - 1] == INF) {
        cout << -1;
    } else {
        cout << dp[n - 1];
    }
}

int main() {
    fast
    solve();
    return 0;
}
