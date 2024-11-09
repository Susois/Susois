#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,d,h;cin>> n >> d >> h;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int64_t> dp(n,1e18);
    dp[0]  = a[0];
    for(int i=0;i<n;i++){
        if(dp[i]==1e18)continue;
        for(int j=i+1;j<n;j++){
            if(j-i<=d && abs(a[i]-a[j])<=h){
                dp[j] = min(dp[j], dp[i] + a[j]);
            }
        }
    }
    cout<<  ( dp.back()==1e18 ? -1 : dp.back() );
}
