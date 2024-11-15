#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long n;cin>>n;
    long long a[2007];
    long long c=0,s=0;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i] = a[i] ^ a[i-1];
        if(a[i] ==0)s=i;
    }
    for(int i=1;i<=s;i++){
        if(a[i]==a[n])c=1;
    }
    if(c){
        cout<< "YES" << '\n';
        return;
    }
    else {
        cout << "NO" << '\n';
        return;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}