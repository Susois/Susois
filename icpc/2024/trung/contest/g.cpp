#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve(){
    int n,m;cin>>n>>m;
    int a,b;cin>>a>>b;
    if((a==1&&b==1) || (a==1 && b==m) || (a==n && b==1) || (a==n && b==m) ){cout<<3;return ;}
    else {
        if(a==1 || a==n ){
            cout<<5;
            return;
        }
        else {
            if(b==1 || b==m){
                cout<<5;
                return;
            }
            else {
                cout<<8;
                return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // int t;cin>>t;
    // while(t--){
    solve();
    // }
    return 0;
}