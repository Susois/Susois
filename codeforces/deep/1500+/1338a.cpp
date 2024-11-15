#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    long long maxi = 0;
    for(int i=1;i<n;i++){
        if(a[i] < a[i-1]){
            maxi = max(maxi, a[i-1]-a[i]);
            a[i] = a[i-1];
        }
    }
    cout<<(int)ceil(log2(maxi+1))<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}