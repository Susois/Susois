#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, S, ans=0;
    cin >> n >> S;
    vector<int> val(n+1);
    int truyvet[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    int dp[S+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int s=0;s<=S;s++)
    {
        for(int i=1;i<=n;i++)
        {
            if(s>=val[i])
            {
                dp[s] = (dp[s] + dp[s-val[i]])%MOD;
            }
        }
    }

    cout << dp[S] << endl;
    return 0;
}
