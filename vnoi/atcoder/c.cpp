#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    int a,b,c;
    int dp[n+1][4];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;

        dp[i][1] = max( dp[i-1][2] + a, dp[i-1][3] + a);
        dp[i][2] = max( dp[i-1][1] + b, dp[i-1][3] + b);
        dp[i][3] = max (dp[i-1][1] + c, dp[i-1][2] + c); 
    }
    cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));

    return 0;
}