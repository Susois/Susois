#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, r;
    cin >> s >> r;

    // Kiểm tra nếu có ít nhất một cặp s_k != s_k+1
    int k = 0;
    for(int i=0;i<s.length()-1;i++){
        while(s[i]!=s[i+1]){
            s[i] = r[k];
            k++;
            s.erase(i+1,1);
        }
    }
    // for(int i=s.length()-1; i>=0; i--) {
    //     while(s[i]!=s[i+1]){
    //         s[i] = r[k];
    //         k++;
    //         s.erase(i+1,1);
    //     }
    // }
    if(s.length()==1)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
