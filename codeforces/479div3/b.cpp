#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    
    unordered_map<string,int> mp;
    for(int i=0;i<n-1;i++){
        mp[s.substr(i,2)] ++;
    }

    int maxn = 0;
    string res="";
    for(auto x:mp){
        if(x.second>maxn){
            maxn = x.second;
            res = x.first;
        }
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}