#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int cnt = 0;
    for(int i=0;i<n-2;i++){
        if(s[i] == 'x' && s[i+1]=='x' && s[i+2]=='x')cnt++;
    }
    cout<<cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}