#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
int parent[maxn], size[maxn];

void make_set(int v) {
    parent[v] = v;
    size[v] = 1; 
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a; 
        size[a] += size[b]; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    ll mst_weight = 0; 
    for (auto edge : edges) {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find_set(u) != find_set(v)) {
            mst_weight += w;
            union_sets(u, v);
        }
    }

    cout << mst_weight << "\n";

    return 0;
}
