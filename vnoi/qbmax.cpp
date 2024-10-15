#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m,res =INT_MAX;cin>>n>>m;
    int se[n+2][m+2];
    int dp[n+2][m+2];
    memset(dp,0,sizeof(dp));
    memset(se,0,sizeof(se));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>se[i][j];
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            // dp[i][j] = max( dp[i-1][j-1]+se[i][j], max(dp[i][j-1]+se[i][j] , dp[i+1][j]+se[i][j]));
            dp[i][j] = max( dp[i-1][j-1] + se[i][j] , max(dp[i][j-1] + se[i][j], dp[i+1][j-1] + se[i][j]));
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<se[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    // for(int i=1;i<=n;i++)
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }
    // res = min(res ,dp[i][m]);
    cout<<res;
    return 0;
}