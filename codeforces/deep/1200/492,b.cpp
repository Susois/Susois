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
cin.tie(0);cout.tie(0);             
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    vector<int> se(n);
    for(int i=0;i<n;i++)cin>>se[i];
    sort(se.begin(),se.end());
    int maxx= INT_MIN;
    for(int i=1;i<n;i++){
        if(se[i] - se[i-1] >= maxx) maxx = se[i] - se[i-1];
    }
    float res = (float)maxx/2;
    res = max(res, (float)se[0]);
    printf("%.10f",res);

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