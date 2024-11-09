#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<tuple<int,int,int>> se(n);
    for(int i=0;i<n;i++){
        auto &&[x,y,z]= se[i];
        cin>>x>>y>>z;
        y = -y;
    }
    vector<int64_t> dp(n);
    sort(se.begin(),se.end());
    for(int i=0;i<n;i++){
        dp[i] = max<int64_t>(get<2>(se[i]),dp[i]);        ;
        for(int j=i+1;j<n;j++){
            if(get<1>(se[i]) >= get<1>(se[j])) dp[j] = max<int64_t>(dp[j],dp[i]+get<2>(se[j]));
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}