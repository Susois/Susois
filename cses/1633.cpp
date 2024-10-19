#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 +1;
const int mod = 1e9 +7;
long long dp[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    memset(dp,1,sizeof(dp));
    dp[0] = 1 %mod;
    dp[1] = 1 %mod;
    dp[2] = 2 %mod;
    dp[3] = 4%mod;
    dp[4] = 8%mod;
    dp[5] = 16%mod;
    dp[6] = 32%mod;
    for(int i=6;i<=n;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] +dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%mod;
    }
    cout<<dp[n];
}