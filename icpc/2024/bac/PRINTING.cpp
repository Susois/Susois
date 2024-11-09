#include <bits/stdc++.h>
using namespace std;

namespace std {

template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Dimension must be positive");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};

template <typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};

/* Example
    Vec<4, int64_t> f(n, k, 2, 2); // = f[n][k][2][2];
    Vec<2, int> adj(n); // graph
*/

template <class Fun>
class y_combinator_result {
    Fun fun_;

   public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

    template <class... Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

/* Example
    auto fun = y_combinator([&](auto self, int x) -> void {
        self(x + 1);
    });
*/

}  // namespace std

class DSU {
   public:
    DSU(int n) {
        prt.resize(n + 1, -1);
    }

    int SZ(int u) {
        return -prt[root(u)];
    }

    int root(int u) {
        return (prt[u] < 0 ? u : (prt[u] = root(prt[u])));
    }

    bool connected(int u, int v) {
        return ((u = root(u)) == (v = root(v)));
    }

    bool unite(int u, int v) {
        if ((u = root(u)) == (v = root(v))) {
            return 0;
        }

        if (prt[u] > prt[v]) {
            u ^= v ^= u ^= v;
        }

        prt[u] += prt[v];
        prt[v] = u;
        return 1;
    }

   private:
    vector<int> prt;
};

struct blossom {
    int n, m;
    vector<int> mate;
    vector<vector<int>> b;
    vector<int> p, d, bl;
    vector<vector<int>> g;
    blossom(int n) : n(n) {
        m = n + n / 2;
        mate.assign(n, -1);
        b.resize(m);
        p.resize(m);
        d.resize(m);
        bl.resize(m);
        g.assign(m, vector<int>(m, -1));
    }
    void add_edge(int u, int v) {
        g[u][v] = u;
        g[v][u] = v;
    }
    void match(int u, int v) {
        g[u][v] = g[v][u] = -1;
        mate[u] = v;
        mate[v] = u;
    }
    vector<int> trace(int x) {
        vector<int> vx;
        while (true) {
            while (bl[x] != x) x = bl[x];
            if (!vx.empty() && vx.back() == x) break;
            vx.push_back(x);
            x = p[x];
        }
        return vx;
    }
    void contract(int c, int x, int y, vector<int> &vx, vector<int> &vy) {
        b[c].clear();
        int r = vx.back();
        while (!vx.empty() && !vy.empty() && vx.back() == vy.back()) {
            r = vx.back();
            vx.pop_back();
            vy.pop_back();
        }
        b[c].push_back(r);
        b[c].insert(b[c].end(), vx.rbegin(), vx.rend());
        b[c].insert(b[c].end(), vy.begin(), vy.end());
        for (int i = 0; i <= c; i++) {
            g[c][i] = g[i][c] = -1;
        }
        for (int z : b[c]) {
            bl[z] = c;
            for (int i = 0; i < c; i++) {
                if (g[z][i] != -1) {
                    g[c][i] = z;
                    g[i][c] = g[i][z];
                }
            }
        }
    }
    vector<int> lift(vector<int> &vx) {
        vector<int> A;
        while (vx.size() >= 2) {
            int z = vx.back();
            vx.pop_back();
            if (z < n) {
                A.push_back(z);
                continue;
            }
            int w = vx.back();
            int i = (A.size() % 2 == 0 ? find(b[z].begin(), b[z].end(), g[z][w]) - b[z].begin() : 0);
            int j = (A.size() % 2 == 1 ? find(b[z].begin(), b[z].end(), g[z][A.back()]) - b[z].begin() : 0);
            int k = b[z].size();
            int dif = (A.size() % 2 == 0 ? i % 2 == 1 : j % 2 == 0) ? 1 : k - 1;
            while (i != j) {
                vx.push_back(b[z][i]);
                i = (i + dif) % k;
            }
            vx.push_back(b[z][i]);
        }
        return A;
    }
    int solve() {
        for (int ans = 0;; ans++) {
            fill(d.begin(), d.end(), 0);
            queue<int> Q;
            for (int i = 0; i < m; i++) bl[i] = i;
            for (int i = 0; i < n; i++) {
                if (mate[i] == -1) {
                    Q.push(i);
                    p[i] = i;
                    d[i] = 1;
                }
            }
            int c = n;
            bool aug = false;
            while (!Q.empty() && !aug) {
                int x = Q.front();
                Q.pop();
                if (bl[x] != x) continue;
                for (int y = 0; y < c; y++) {
                    if (bl[y] == y && g[x][y] != -1) {
                        if (d[y] == 0) {
                            p[y] = x;
                            d[y] = 2;
                            p[mate[y]] = y;
                            d[mate[y]] = 1;
                            Q.push(mate[y]);
                        } else if (d[y] == 1) {
                            vector<int> vx = trace(x);
                            vector<int> vy = trace(y);
                            if (vx.back() == vy.back()) {
                                contract(c, x, y, vx, vy);
                                Q.push(c);
                                p[c] = p[b[c][0]];
                                d[c] = 1;
                                c++;
                            } else {
                                aug = true;
                                vx.insert(vx.begin(), y);
                                vy.insert(vy.begin(), x);
                                vector<int> A = lift(vx);
                                vector<int> B = lift(vy);
                                A.insert(A.end(), B.rbegin(), B.rend());
                                for (int i = 0; i < (int)A.size(); i += 2) {
                                    match(A[i], A[i + 1]);
                                    if (i + 2 < (int)A.size()) add_edge(A[i + 1], A[i + 2]);
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if (!aug) return ans;
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    vector<int> cnt(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (x > y) swap(x, y);
        cnt[x]++;
        if (y == x + 1) cnt[y]++;
        dsu.unite(x, y);
    }

    vector<int> sum(n);
    for (int i = 0; i < n; i++) {
        sum[dsu.root(i)] += cnt[i];
    }

    vector<int> done(n);

    for (int i = 0; i < n; i++) {
        if (sum[dsu.root(i)] >= dsu.SZ(i)) {
            done[i] = 1;
        }
    }

    blossom G(n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == dsu.root(i)) ans += done[i] == 0;
    }

    for (int i = 0; i + 1 < n; i++) {
        if (done[i] || done[i + 1]) continue;
        G.add_edge(dsu.root(i), dsu.root(i + 1));
    }
    cout << ans - G.solve();
}

