#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;
    vector<int> dp(s + 1, 0);
    dp[0] = 1; 
    vector<int> val(n);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        dp[val[i]]=1;
    }


    for (int i = 1; i <= n; i++) {
        for (int j = val[i]; j <= s; j++) {
            dp[j] = (dp[j] + dp[j - val[i]] ) % MOD;
        }
    }

    cout << dp[s] << endl;

    return 0;
}
