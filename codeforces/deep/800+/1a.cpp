#include<bits/stdc++.h>
#define ll long long
#define lli int64_t
#define fi first 
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fint(i,x) for(int i=1;i<=x;i++)
#define fstr(i,s) for(int i=0;i<sz(s);i++)
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
    lli a,b,c;cin>>a>>b>>c;
    lli res1=0,res2=0,res=0;
    if(a%c==0)res1 = a/c;
    else res1= a/c +1;
    if(b%c==0)res2 = b/c;
    else res2 = b/c +1;
    res = res1 * res2;
    cout<<res;
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