#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 +1;
int parent[maxn];
void make_set(int v)
{
    parent[v] = v;
    // sz[v] = 1; kich co
    // rank[v] = 0; // goc cua day co do cao la 0
}
int find_set(int v)
{
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void unions_sets(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        parent[a] = b; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        if(a==1)
        {
            make_set(b);
            make_set(c);
            unions_sets(b,c);
            unions_sets(c,b);
        }
    }
}