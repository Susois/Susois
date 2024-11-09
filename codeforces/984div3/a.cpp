#include<bits/stdc++.h>
using namespace std;
void solve()
{
    bool ok=true;
    int n;cin>>n;
    vector<int> se(n);
    for(int i=0;i<n;i++)cin>>se[i];
    for(int i=1;i<n;i++){
        if(abs(se[i] - se[i-1]) != 5 && abs(se[i-1] - se[i])!=7 )ok = false;
    }
    if(ok)cout<<"YES";
    else cout<<"NO";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;
    while(t--){
        solve(),
        cout<<'\n';
    }
}