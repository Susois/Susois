#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;cin>>n;
    string s = "codeforces";
    long long cur = 1;
    vector<long long> b(10,1);
    for(long long i=0;cur<n; i = (i+1)%10){
        cur = cur / b[i] * (b[i]+1);
        b[i]++;
    }
    for(long long i=0;i<10;i++){
        for(long long j=1;j<=b[i];j++){
            cout<<s[i];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
     return 0;
}