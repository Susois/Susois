#include <bits/stdc++.h>
using namespace std;

int minOperations(const string &s, const string &t) {
    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i < n && dp[i][j] != INT_MAX) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            if (j < m && dp[i][j] != INT_MAX) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }
            if (dp[i][j] != INT_MAX) {
                dp[n][m] = min(dp[n][m], dp[i][j] + (n - i) + (m - j) + 1);
            }
        }
    }

    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    while (q--) {
        string s, t;
        cin >> s >> t;
        cout << minOperations(s, t) << "\n";
    }

    return 0;
}
