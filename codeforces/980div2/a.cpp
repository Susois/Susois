#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve(){
    int a,b;cin>>a>>b;
    if(a>=b)    
        {
            cout<<a<<'\n';
            }
    else {
        int tmp = b-a;
        if(a-tmp <=0 || b - tmp*2 <=0)cout<<0<<'\n';
        else
            cout<< b-tmp*2<<'\n';
    }
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