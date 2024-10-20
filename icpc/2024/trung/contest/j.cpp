#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int LOG = 17; 
int n, q;
vector<int> g[maxn];
int parent[maxn][LOG];  
int depth[maxn];       
int tin[maxn], tout[maxn], timer = 0; 

void dfs(int u, int p) {
    tin[u] = ++timer;
    parent[u][0] = p;
    for (int i = 1; i < LOG; i++) {
        if (parent[u][i - 1] != -1) {
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
        }
    }

    for (int v : g[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = LOG - 1; i >= 0; i--) {
        if (!is_ancestor(parent[u][i], v)) {
            u = parent[u][i];
        }
    }
    return parent[u][0];
}

void solve() {
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(parent, -1, sizeof(parent));

    dfs(1, -1);

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int lca_xz=lca(x,z);
        if (is_ancestor(lca_xz,y) && is_ancestor(y,x) || is_ancestor(y,z)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
