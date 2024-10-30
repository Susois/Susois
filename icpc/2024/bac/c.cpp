#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    
    // Read input matrix
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    
    ll max_sum = -1;
    ll col_sum[m+1];

    for (int r1 = 1; r1 <= n; r1++) {   
        memset(col_sum, 0,sizeof(col_sum));

        for (int r2 = r1; r2 <= n; r2++) {
            unordered_map<ll, ll> summod;
            summod[0] = 0;
            ll csum = 0;

            for (int c = 1; c <= m; c++) {
                col_sum[c] += a[r2][c];
                csum += col_sum[c];
                
                ll mod = (csum % k + k) % k;

                if (summod.count(mod)) {
                    max_sum = max(max_sum, csum - summod[mod]);
                }

                if (!summod.count(mod) || csum < summod[mod]) {
                    summod[mod] = csum;
                }
            }
        }
    }

    cout << (max_sum == -1 ? 0 : max_sum) << endl;
}

int main() {
    fast
    solve();
    return 0;
}
