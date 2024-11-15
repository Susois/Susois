#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<long long> a(n);
    for(int i=0; i<n; i++)cin>>a[i];
    map<int,int> dp;
    int ans= 0;
    int lst = 0;
    for(int i=0;i<n;i++){
        int x = a[i];
        dp[x]  = dp[x-1] + 1;
        if(ans < dp[x]){
            ans = dp[x];
            lst = x;
        }
    }

    multiset<int> res;
    for(int i=n-1;i>=0;i--){
        if(a[i]==lst){
            res.insert(i);
            lst--;
        }
    }
    cout<<ans<<"\n";
    for(auto i:res)cout<<i+1<<" ";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}