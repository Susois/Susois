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
    string s;cin>>s;
    int cnt=0;
    bool check = false;
    fstr(i,s) {
        if(s[i] >= 'A' && s[i] <= 'Z')cnt++;
    }
    if(cnt > (sz(s)-cnt))check =true;
    if(check) fstr(i,s) {
            s[i] = toupper(s[i]);
    }
    else fstr(i,s) {
        s[i] = tolower(s[i]);
    }
    cout<<s<<'\n';
    
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