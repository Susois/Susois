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
#define pa pair<int,int>
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
    int n,k,tmp=0;cin>>n>>k;
    vec se(n);
    for(int i=0;i<n;i++)cin>>se[i];
    if(se[0] ==0 ){
        cout<<0;
        re;
    }
    tmp = se[k-1];
    int cnt=0;
    for(int i=0;i<n;i++)if(se[i] >= tmp && se[i]!=0)cnt++;
    cout<<cnt;
}
int main(){
    fast

    // int t;cin>>t;
    // while(t--){
    solve();
    cout<<'\n';
    // }
    return 0;
}