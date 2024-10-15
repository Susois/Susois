#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
int n,m,a,b,minn = INT_MAX;
vector<int> g[maxn];
bool VisitRei[maxn]={false};
bool VisitMa[maxn]={false};
// int aMa[maxn]= {0},aRei[maxn]={0};
int cntMa[maxn] = {0},cntRei[maxn] = {0};



void bfsa(int s)
{
    queue<int> q;
    q.push(s);
    VisitMa[s] = true;
    cntMa[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : g[u])
        {
            if(!VisitMa[v])
            {
                VisitMa[v] = true;
                cntMa[v] = cntMa[u] + 1;
                q.push(v);
            }
        }
    }
}

void bfsb(int s)
{
    queue<int> q;
    q.push(s);
    VisitRei[s] = true;
    cntRei[s] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : g[u])
        {
            if(!VisitRei[v])
            {
                VisitRei[v] = true;
                cntRei[v] = cntRei[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    cin>>a>>b;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfsa(a);
    bfsb(b);

    for(int i=1;i<=n;i++)
    {
        if(cntMa[i] == cntRei[i] && cntMa[i] <= minn)minn = cntMa[i];
    }
    if(minn!=INT_MAX)cout<<minn;
    else cout<<-1;
    return 0;

}