#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve()
{
    int n,x,check=1;cin>>n>>x;
    vector<int> a(n),b(n);
    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    for(int i=0;i<n;i++)
    {
        if(a[i] + b[i] > x )
        {
            check =0;
            break;
        }
    }
    if(check)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}