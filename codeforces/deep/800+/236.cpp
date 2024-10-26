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
    string s;cin>>s;
    set<char> se;
    se.insert(s[0]);
    for(int i=1;i<sz(s);i++){
        if(!se.empty() &&  se.count(s[i]) == 0 )se.insert(s[i]);
    }
    // cout<<sz(se)<<'\n';
    if(sz(se)%2==0)cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";
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