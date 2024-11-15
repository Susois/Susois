#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int res = a[0]==1;
    for(int i=1;i<n;i++){
        if(a[i]==0)continue;
        int j=i;
        while(j<n && a[j]==1){
            j++;
        }
        res += (j-i)/3;
        i=j-1;
    }
    cout<<res<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;cin>>t;
    while(t--)solve();
    return 0;
}