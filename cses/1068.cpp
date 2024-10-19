#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    unsigned long long n;
    cin>>n;
        cout<<n<<" ";
    while(n!=1)
    {
        if(n%2==0)n/=2;
        else n = n*3 +1;
        cout<<n<<" ";
    }
    return 0;
}