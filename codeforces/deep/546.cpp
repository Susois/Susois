#include<bits/stdc++.h>
#define ll long long
#define lli int64_t
#define fi first 
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define mp make_pair
#define pb push_back
#define vec vector<int> 
#define pii pair<int,int>
#define re return
#define br break
#define fast                        \
ios_base::sync_with_stdio(false);   \
cin.tie(0);cout.tie(0);             \
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

void solve(){
    int k,n,w;cin>>k>>n>>w;
    lli s = 0;
    
    for(int i=1;i<=w;i++){
        s += (k*i);
    }
    if(s>=n)cout<<s-n;
    else cout<<0;
}
int main(){
    fast

    // int t;cin>>t;
    // while(t--){
    // solve();
    // cout<<'\n';
    // }
    solve();
    return 0;
}