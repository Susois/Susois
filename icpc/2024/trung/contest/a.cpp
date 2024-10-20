// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int n, m, h;
//     cin >> n >> m >> h;
//     vector<int> w(n), c(n);
//     for (int i = 0; i < n; i++) {
//         cin >> w[i] >> c[i];
//     }
//     const int N = n * 1000 + 1;
//     vector<vector<int64_t>> dp(2, vector<int64_t>(N, 1e18));
//     dp[0][0] = 0;
//     for (int i = 0; i < n; i++) {
//         vector<vector<int64_t>> dp2(2, vector<int64_t>(N, 1e18));
//         for (int j = 0; j < N; j++) {
//             for (int z = 0; z < 2; z++) {
//                 if (j + c[i] < N) dp2[z][j + c[i]] = min(dp2[z][j + c[i]], dp[z][j] + w[i]);
//                 dp2[z][j] = min(dp2[z][j], dp[z][j]);
//             }
//             if (w[i] <= h && j + c[i] < N) dp2[1][j + c[i]] = min(dp2[1][j + c[i]], dp[0][j]);
//         }
//         dp = dp2;
//     }

//     for (int i = N - 1; i >= 0; i--) {
//         if (dp[0][i] <= m || dp[1][i] <= m) {
//             cout << i << endl;
//             return 0;
//         }
//     }

//     cout << -1 << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, h;
    cin >> n >> m >> h;
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> c[i];
    }

    const int N = n * 1000 + 1;
    vector<int64_t> dp0(N, 1e18), dp1(N, 1e18);
    dp0[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<int64_t> new_dp0 = dp0, new_dp1 = dp1;
        for (int j = 0; j < N; j++) {
            if (j + c[i] < N) {
                new_dp0[j + c[i]] = min(new_dp0[j + c[i]], dp0[j] + w[i]);
                new_dp1[j + c[i]] = min(new_dp1[j + c[i]], dp1[j] + w[i]);
                if (w[i] <= h) {
                    new_dp1[j + c[i]] = min(new_dp1[j + c[i]], dp0[j]);
                }
            }
            new_dp0[j] = min(new_dp0[j], dp0[j]);
            new_dp1[j] = min(new_dp1[j], dp1[j]);
        }
        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    for (int i = N - 1; i >= 0; i--) {
        if (dp0[i] <= m || dp1[i] <= m) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
