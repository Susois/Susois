#include<bits/stdc++.h>
using namespace std;
int cnt3(long long x){
    int res = 0;
    while(x % 3 ==0){
        res++;
        x /= 3;
    }
    return res;
}
void solve(){
    int n;cin>>n;
    vector<pair<int, long long>> se(n);
    for(int i=0; i<n; i++){
        cin>>se[i].second;
        se[i].first = -cnt3(se[i].second);
    }
    sort(se.begin(), se.end());
    for(int i=0; i<n; i++){
        cout<<se[i].second<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}