#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 +5;
vector<int> g[N];
bool Visit[N];
int cnt = 0;
void bfs(int s){
    bool ok = true;
    queue<int> q;
    q.push(s);
    Visit[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(g[u].size()!=2)ok=false;
        for(auto v : g[u]){
            if(!Visit[v]){
                Visit[v] = true;
                q.push(v);
            }
        }
    }
    if(ok)cnt++;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(Visit, false, sizeof(Visit));
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!Visit[i]){
            bfs(i);
        }
    }
    cout<<cnt;
    return 0;
}