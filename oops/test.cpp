#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, d, h;
    cin >> n >> d >> h;
    vector<ll> arr(n), dp(n, 1e18);
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    // cout << dp[0];
    for(ll i = 0; i < n; i++){
        if(dp[i]==1e18) continue;
        // cout << dp[i] << endl;
        // for(ll j = i+1; j <= i+d && j < n; j++){
        for(ll j = i+1; j < n; j++){
            if(abs(arr[i]-arr[j]<= h) && j-i<=d){
                dp[j] = min(dp[j], dp[i]+arr[j]);
            }
        }
    }
    cout << (dp[n-1] == 1e18 ? -1 : dp[n-1]);
    return 0;
}