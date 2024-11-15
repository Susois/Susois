#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
bool Visit[maxn];
void solve(){
    #define int long long
    memset(Visit, false, sizeof(Visit));
    int n;cin>>n;
    int se[maxn];
    memset(se,0,sizeof(se));
    vector<long long> pref(n+1,0);
    for(int i=1;i<=n;i++)
    {
        long long a;cin>>a;
        se[a]++;
        pref[i] = pref[i-1] + a;
    }
    long long cnt=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            long long k = pref[i] - pref[j-1];
            if(k>n)continue;
            if(Visit[k])continue;
            Visit[k] = true;
            cnt +=se[k];

        }
    }
    cout<<cnt<<'\n';
}
#undef int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}