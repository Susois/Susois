#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int n;
int a[N];
int tree[N*4];
void buildtree(int id, int l, int r)
{
    if(l==r)
    {
        tree[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    buildtree(id*2,l,mid);
    buildtree(id*2+1,mid+1,r);

    tree[id] = max(tree[id*2], tree[id*2+1]);
}

void update(int id, int l, int r, int u, int v,int val)
{
    if(u>r || v<l)
        return ;
    if(l == r ){tree[id] += val;
    return;
    }

    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);

    tree[id] = max(tree[id*2],tree[id*2+1]);
}

int getval(int id, int l , int r, int u, int v)
{
    if(u>r || v<l)
        return INT_MIN;
    if(l==r)return tree[id];
    int mid = (l+r)/2;
    return max(getval(id*2,l,mid,u,v),getval(id*2+1,mid+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    buildtree(1,1,n);

    int t;cin>>t;
    while(t--)
    {
        char s;cin>>s;
        if(s=='x')
        {int x,y,v;cin>>x>>y>>v;
        update(1,1,n,x,y,v);
        }
        else {
            int x,y;cin>>x>>y;
            cout<<getval(1,1,n,x,y)<<"\n";
        }
    }

    // for(int i=1;i<=n*4;i++)cout<<tree[i];
    return 0;
}