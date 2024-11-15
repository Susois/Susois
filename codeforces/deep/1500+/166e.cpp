#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 +7;
void solve(){
    int n;cin>>n;
    vector<long long> dp(n+1);
    dp[1] = 0;
    dp[2] = 3;
    for(int i=3;i<=n;i++){
        if(i%2==0)dp[i] = dp[i-1] * 3 + 3;
        else dp[i] = dp[i-1] * 3 - 3;
        dp[i] %= mod;
    }
    cout<<dp[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    solve();
    return 0;
}