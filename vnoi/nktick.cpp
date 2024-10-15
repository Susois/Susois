#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    int dp[n+1],t[n+1],r[n+1];
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)cin>>t[i];
    for(int i=1;i<=n-1;i++)cin>>r[i];
    dp[0] = 0;
    dp[1] = t[1];
    for(int i=2;i<=n;i++)
    {
        dp[i] = min(dp[i-1]+t[i],dp[i-2]+r[i-1]);
    }
    cout<<dp[n];
    return 0;

}