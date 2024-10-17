#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int parent[maxn]; 
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> p(n); 
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    parent[n+1] = 1; 
    for (int i = 0; i < n; i++) {
        int pos = p[i];
        int parking_pos = find_set(pos); 
        cout << parking_pos << " "; 
        union_sets(parking_pos, parking_pos % n + 1);
    }

    return 0;
}
