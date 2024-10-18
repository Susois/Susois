#include<bits/stdc++.h>
using namespace std;
const int maxn =1e5+1;
bool checktang(vector<int> a)
{
    for(int i=1;i<a.size();i++)
    {
        if(a[i] <a[i-1])return false;
    }
    return true;
}
bool checkgiam(vector<int> a)
{
    for(int i=1;i<a.size();i++)
    {
        if(a[i]>a[i-1])return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;cin>>n;
    vector<int> se(n);
    for(int i=0;i<n;i++)cin>>se[i];
    if(checktang(se) || checkgiam(se))cout<<"YES";
    else cout<<"NO";
    return 0;
}