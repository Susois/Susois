#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;
vector<int> g[MAXN];  
bool se(int u, int v, int n) {
    vector<bool> visited(n+1, false);
    queue<int> aq;
    q.push(u);
    visited[u] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == v) return true; 
        for (int next : g[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    
    return false; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); 
    }

    int t; cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (se(x, y, n)) {
            cout << "Yes"<<'\n';
        } else {
            cout << "No"<<'\n';
        }
    }

    return 0;
}
