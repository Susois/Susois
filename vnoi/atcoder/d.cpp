#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cout.tie(0);

    long long n,s;cin>>n>>s;
    long long v[n+1],w[n+1],dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)cin>>w[i]>>v[i];

    for(int j=1;j<=s;j++)

    {
        for(int i=1;i<=n;i++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=w[i])dp[i][j] = max ( dp[i-1][j] , dp[i-1][j-w[i]]+v[i]);
        }
    }
    cout<<dp[n][s]<<'\n';
    return 0;
}
