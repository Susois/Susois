#include <bits/stdc++.h>
using namespace std;
const int LOG = 17;
const int maxn = 100005;
vector<int> cay[maxn];
int cha[maxn][LOG];
int dep[maxn];
// int tin[maxn], tout[maxn], timer = 0;
void dfs(int u, int par)
{
    // tin[u] = ++timer;/
    cha[u][0] = par;
    for (int i = 1; i < LOG; i++)
    {
        if (cha[u][i - 1] != -1)
            cha[u][i] = cha[cha[u][i - 1]][i - 1];
    }

    for (int v : cay[u])
    {
        if (v != par)
        {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
    // tout[u] = ++timer;//
}

int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    int diff = dep[u] - dep[v];
    for (int i = 0; i < LOG; i++)
    {
        if ((diff >> i) & 1)
        {
            u = cha[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (cha[u][i] != cha[v][i])
        {
            u = cha[u][i];
            v = cha[v][i];
        }
    }
    return cha[u][0];
}

bool totien(int a, int b)
{
    // return tin[u] <= tin[v] && tout[u] >= tout[v];
    return lca(a, b) == a;
}
bool check(int u, int v, int y)
{
    int lca_uv = lca(u, v);
    return (totien(y, u) && totien(lca_uv, y)) || (totien(y, v) && totien(lca_uv, y));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        cay[u].push_back(v);
        cay[v].push_back(u);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < LOG; j++)
        {
            cha[i][j] = -1;
        }
    }
    dep[1] = 0;
    dfs(1, -1);
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (check(x, z, y))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
