#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        long long resa =pow(2,n), resb= 0;
        for(int i=1;i<n/2;i++)resa+= pow(2,i);
        for(int i=n/2;i<n;i++)resb+= pow(2,i);
        cout<<resa - resb<<'\n';
    }
    return 0;
}