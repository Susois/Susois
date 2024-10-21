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
#define su exit(0)
#define fast                        \
ios_base::sync_with_stdio(false);   \
cin.tie(0);cout.tie(0);             \
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);


using namespace std;

int cnt  =0;

void solve(){
    string s;cin>>s;
    if(s=="Icosahedron")cnt+=20;
    else if(s=="Cube")cnt+=6;
    else if(s=="Tetrahedron")cnt+=4;
    else if(s=="Dodecahedron")cnt+=12;
    else cnt+=8;
}
int main(){
    fast

    int t;cin>>t;
    while(t--){
    solve();
    }
    cout<<cnt;
    return 0;
}