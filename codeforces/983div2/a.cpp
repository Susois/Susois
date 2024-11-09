#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,cnt0=0,cnt1=0;cin>>n;
    vector<int> se(2*n+5);
    for(int i=1;i<=2*n;i++){
        cin>>se[i];
        if(se[i]==0)cnt0++;
        else cnt1++;
    }
    int tmp = min(cnt0,cnt1);
    cout<<tmp%2<<" "<<tmp;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
    return 0;
}