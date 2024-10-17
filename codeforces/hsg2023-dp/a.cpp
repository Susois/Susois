#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;
    unsigned long long dp[100];
    memset(dp,0,sizeof(dp));
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3;i<=93;i++)dp[i] = dp[i-1]+ dp[i-2];
    while(t--)
    {
        int n;cin>>n;
        cout<<dp[n+1]<<endl;
    }
    return 0;
}