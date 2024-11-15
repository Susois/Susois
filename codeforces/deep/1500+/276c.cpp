#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;cin>>n>>m;
    vector<int> se(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>se[i];
    }
    sort(se.begin(),se.end());
    int pref[n+2];
    int a[n+2];
    memset(a,0,sizeof(a));
    memset(pref,0,sizeof(pref));
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        a[u]++;
        a[v+1]--;
    }
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1] + a[i];
    }
    sort(pref+1,pref+n+1);
    long long res = 0;
    for(int i=1;i<=n;i++){
        res += (long long)se[i]*pref[i];
    }
    // for(int i=1;i<=n;i++)cout<<pref[i]<<" ";
    // cout<<'\n';
    // for(auto x:se)cout<<x<<" ";
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}