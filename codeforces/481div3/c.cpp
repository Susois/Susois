#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve(){
    int n,m;cin>>n>>m;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i] += a[i-1];
    }

    while(m--){
        int r;cin>>r;
        int pos = 0,res=0;
        pos = lower_bound(a.begin(),a.end(),r)-a.begin();
        res = r - *(lower_bound(a.begin(),a.end(),r)-1);
        cout<<pos<<" "<<res<<endl;
    }
}
#undef int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}