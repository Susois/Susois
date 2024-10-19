#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    // int t;cin>>t;
    // while(t--){}
    int n;cin>>n;
    bool a[n+1];
    memset(a,false,sizeof(a));
    for(int i=1;i<n;i++)
    {
        int x;cin>>x;
        a[x] = true;
    }
    for(int i=1;i<=n;i++)
    if(a[i]==false){cout<<i;
    return 0;}
}