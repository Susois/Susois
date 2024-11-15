#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n, a, b; cin >> n >> a >> b;
    if(b==1){
        cout<<"Yes\n";
        return;
    }
    if (a == 1) {
        cout << ((n - 1) % b == 0 ? "Yes\n": "No\n");
        return;
    }
 
    long long m=1;
    bool res=false;
    while (m <= n) {
        if (m % b == n % b) {
            res = true;
            break;
        }
        m *= a;
    }
 
    cout << (res ? "Yes\n": "No\n");
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}