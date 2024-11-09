#include <bits/stdc++.h>

using namespace std;

#define             fi  first
#define             se  second
#define           left  ___left___
#define          right  ___right___
#define   scan_op(...)  istream & operator >> (istream &in, __VA_ARGS__ &u)
#define  print_op(...)  ostream & operator << (ostream &out, const __VA_ARGS__ &u)
#define     file(name)  if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#ifdef LOCAL
    #include "debug.h"
#else
    #define DB(...)
    #define db(...) ""
    #define debug(...)
#endif

namespace std {
template <class U, class V> scan_op(pair <U, V>) { return in >> u.first >> u.second; }
template <class T> scan_op(vector <T>) { for (size_t i = 0; i < u.size(); ++i) in >> u[i]; return in; }
template <class U, class V> print_op(pair <U, V>) { return out << '(' << u.first << ", " << u.second << ')'; }
template <size_t i, class T> ostream &print_tuple_utils(ostream &out, const T &tup) { if constexpr(i == tuple_size<T>::value) return out << ")"; else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); }
template <class...U> print_op(tuple <U...>) { return print_tuple_utils<0, tuple <U...>>(out, u); }
template <class Con, class = decltype(begin(declval<Con>()))>typename enable_if <!is_same<Con, string>::value, ostream &>::type operator << (ostream &out, const Con &con) { out << '{'; for (__typeof(con.begin()) it = con.begin(); it != con.end(); ++it) out << (it == con.begin() ? "" : ", ") << *it; return out << '}'; }
template <class T> print_op(stack <T>) { vector <T> v; stack <T> st = u; while (!st.empty()) v.push_back(st.top()), st.pop(); reverse(v.begin(), v.end()); return out << v; }
template <class T> print_op(queue <T>) { queue <T> q = u; out << '{'; while (!q.empty()) { out << q.front(); q.pop(); if (!q.empty()) out << ", "; } out << '}'; return out; }
template <class T, class X, class Y> print_op(priority_queue <T, X, Y>) { priority_queue <T, X, Y> pq = u; out << '{'; while (!pq.empty()) { out << pq.top(); pq.pop(); if (!pq.empty()) out << ", "; } out << '}'; return out; }
template <class Fun> class y_combinator_result { Fun fun_; public: template <class T> explicit y_combinator_result(T &&fun): fun_(forward<T>(fun)) {} template <class...Args> decltype(auto)operator()(Args &&...args) { return fun_(ref(*this), forward<Args>(args)...); } };
template <class Fun> decltype(auto)y_combinator(Fun &&fun) { return y_combinator_result<decay_t<Fun>>(forward<Fun>(fun)); }
template <typename T, int D> struct Vec: public vector <Vec<T, D - 1>> { static_assert(D >= 1, "Vector dimension must be greater than zero!"); template <typename ...Args> Vec(int n = 0, Args ...args): vector <Vec<T, D - 1>>(n, Vec<T, D - 1>(args...)) {} };
template <typename T> struct Vec<T, 1>: public vector<T>{ Vec(int n = 0, const T &val = T()): vector<T>(n, val) {} };
#if __cplusplus < 202002L
    template <class T> int ssize(const T &a) { return a.size(); }
#endif
}

namespace MAX_FLOW {
template <class T> struct Edge {
    int from, to;
    T cap, flow;
    int nxt;
    Edge(int from = 0, int to = 0, T cap = 0, int nxt = -1): from(from), to(to), cap(cap), flow(0), nxt(nxt) {}
};
template <class T> struct PushRelabel {
    int n, max_level;
    vector <Edge <T>> edges;
    vector <vector <int>> lst;
    vector <int> head, level, cnt;
    vector <T> excess;
    vector <bool> active;
    PushRelabel(int n = 0): n(n), lst(n), head(n, -1), level(n), cnt(n + 1), excess(n), active(n) {}
    int add(int from, int to, T cap, bool bi = false) {
        int id = edges.size();
        edges.emplace_back(from, to, cap, head[from]);
        head[from] = id;
        edges.emplace_back(to, from, bi ? cap : 0, head[to]);
        head[to] = id + 1;
        return id;
    }
    void enqueue(int u) {
        if (!active[u] && excess[u] && level[u] < n) {
            active[u] = true;
            lst[level[u]].push_back(u);
            max_level = max(max_level, level[u]);
        }
    }
    T max_flow(int s, int t) {
        for (Edge <T> &e: edges) e.flow = 0;
        max_level = 0;
        for (int i = 0; i < n; ++i) lst[i].clear();
        fill(level.begin(), level.end(), 0);
        fill(excess.begin(), excess.end(), 0);
        fill(cnt.begin(), cnt.end(), 0);
        fill(active.begin(), active.end(), false);
        for (int i = head[s]; i != -1; i = edges[i].nxt) excess[s] += edges[i].cap;
        cnt[0] = n;
        enqueue(s);
        active[t] = true;
        while (max_level >= 0) {
            if (!lst[max_level].empty()) {
                int u = lst[max_level].back();
                lst[max_level].pop_back();
                active[u] = false;
                for (int i = head[u]; i != -1 && excess[u]; i = edges[i].nxt) {
                    T d = min(excess[u], edges[i].cap - edges[i].flow);
                    if (d && level[u] == level[edges[i].to] + 1) {
                        edges[i].flow += d; edges[i ^ 1].flow -= d;
                        excess[edges[i].to] += d; excess[u] -= d;
                        enqueue(edges[i].to);
                    }
                }
                if (excess[u]) {
                    if (cnt[level[u]] == 1) {
                        int k = level[u];
                        for (int u = 0; u < n; ++u) if (level[u] >= k) {
                            --cnt[level[u]];
                            level[u] = n;
                            ++cnt[level[u]];
                            enqueue(u);
                        }
                    } else {
                        --cnt[level[u]];
                        level[u] = n;
                        for (int i = head[u]; i != -1; i = edges[i].nxt)
                            if (edges[i].cap != edges[i].flow) level[u] = min(level[u], level[edges[i].to] + 1);
                        ++cnt[level[u]];
                        enqueue(u);
                    }
                }
            } else max_level--;
        }
        return excess[t];
    }
};
template <class T> struct Dinic {
    static constexpr T inf = numeric_limits<T>::max();
    int n, ss, tt;
    vector <Edge <T>> edges;
    vector <int> head, level, ptr, q;
    Dinic(int n = 0): n(n), head(n, -1), level(n), ptr(n), q(n) {}
    int add(int from, int to, T cap, bool bi = false) {
        int id = edges.size();
        edges.emplace_back(from, to, cap, head[from]);
        head[from] = id;
        edges.emplace_back(to, from, bi ? cap : 0, head[to]);
        head[to] = id + 1;
        return id;
    }
    bool bfs(void) {
        fill(level.begin(), level.end(), n + 1);
        q[0] = ss; level[ss] = 0;
        for (int l = 0, r = 1; l < r; ) {
            int u = q[l++];
            for (int i = head[u]; i != -1; i = edges[i].nxt) if (edges[i].cap != edges[i].flow) {
                int v = edges[i].to;
                if (level[v] == n + 1) {
                    level[v] = level[u] + 1;
                    if (v == tt) return true;
                    q[r++] = v;
                }
            }
        }
        return false;
    }
    T dfs(int u, T pushed) {
        if (u == ss) return pushed;
        T flow = 0;
        for (int &j = ptr[u]; j != -1; j = edges[j].nxt) {
            int i = j ^ 1;
            if (edges[i].cap - edges[i].flow == 0 || level[edges[i].from] >= level[u]) continue;
            T tr = dfs(edges[i].from, min(pushed - flow, edges[i].cap - edges[i].flow));
            if (!tr) continue;
            edges[i].flow += tr;
            edges[j].flow -= tr;
            flow += tr;
            if (flow == pushed) return flow;
        }
        level[u] = n;
        return flow;
    }
    T max_flow(int s, int t) {
        ss = s; tt = t;
        for (Edge <T> &e: edges) e.flow = 0;
        T flow = 0;
        q[0] = ss;
        for (int L = 30; L >= 0; --L) {
            while (true) {
                fill(level.begin(), level.end(), 0);
                int l = 0, r = level[s] = 1;
                while (l < r && !level[t]) {
                    int u = q[l++];
                    for (int i = head[u]; i != -1; i = edges[i].nxt) {
                        if (!level[edges[i].to] && (edges[i].cap - edges[i].flow) >> L) {
                            q[r++] = edges[i].to;
                            level[edges[i].to] = level[u] + 1;
                        }
                    }
                }
                if (!level[t]) break;
                copy(head.begin(), head.end(), ptr.begin());
                flow += dfs(t, inf);
            }
        }
        return flow;
    }
};
template <class Cap, class Cost> struct CEdge {
    int from, to;
    Cap cap, flow;
    Cost cost;
    int nxt;
    CEdge(int from = 0, int to = 0, Cap cap = 0, Cost cost = 0, int nxt = 0): from(from), to(to), cap(cap), flow(0), cost(cost), nxt(nxt) {}
};
template <typename Cap, typename Cost> struct MinCostFlow {
    static constexpr Cap inf_cap = numeric_limits<Cap>::max();
    static constexpr Cost inf_cost = numeric_limits<Cost>::max() >> 1;
    int n;
    vector <CEdge <Cap, Cost>> edges;
    vector <Cost> d, pot;
    priority_queue <pair <Cost, int>> q;
    vector <int> trace, head;
    MinCostFlow(int n_ = 0) : n(n_), d(n), pot(n, 0), trace(n), head(n, -1) {}
    int add(int from, int to, Cap cap, Cost cost) {
        int id = edges.size();
        edges.emplace_back(from, to, cap, cost, head[from]);
        head[from] = id;
        edges.emplace_back(to, from, 0, -cost, head[to]);
        head[to] = id + 1;
        return id;
    }
    void expath(int st) {
        fill(d.begin(), d.end(), inf_cost);
        while (!q.empty()) q.pop();
        d[st] = 0;
        q.push({pot[st], st});
        while (!q.empty()) {
            auto [du, u] = q.top(); q.pop();
            if (du != pot[u] - d[u]) continue;
            for (int i = head[u]; i != -1; i = edges[i].nxt) {
                int v = edges[i].to;
                if (edges[i].cap != edges[i].flow && d[u] + edges[i].cost < d[v]) {
                    d[v] = d[u] + edges[i].cost;
                    trace[v] = i;
                    q.push({pot[v] - d[v], v});
                }
            }
        }
        swap(d, pot);
    }
    pair <Cap, Cost> max_flow(int s, int t) {
        Cap flow = 0;
        Cost cost = 0;
        bool ok = true;
        for (auto &e: edges) if (e.cap != e.flow && e.cost + pot[e.from] - pot[e.to] < 0) {
            ok = false;
            break;
        }
        if (ok) expath(s);
        else {
            vector <int> deg(n, 0);
            for (int u = 0; u < n; ++u)
                for (int i = head[u]; i != -1; i = edges[i].nxt)
                    if (edges[i].cap != edges[i].flow) ++deg[edges[i].to];
            vector <int> que;
            for (int i = 0; i < n; ++i) if (!deg[i]) que.push_back(i);
            for (int b = 0; b < (int) que.size(); ++b) {
                for (int i = head[que[b]]; i != -1; i = edges[i].nxt) if (edges[i].cap != edges[i].flow) {
                    --deg[edges[i].to];
                    if (!deg[edges[i].to]) que.push_back(edges[i].to);
                }
            }
            fill(pot.begin(), pot.end(), inf_cost);
            pot[s] = 0;
            if ((int) que.size() == n) {
                for (int u: que) if (pot[u] < inf_cost) {
                    for (int i = head[u]; i != -1; i = edges[i].nxt) if (edges[i].cap != edges[i].flow && pot[u] + edges[i].cost < pot[edges[i].to]) {
                        pot[edges[i].to] = pot[u] + edges[i].cost;
                        trace[edges[i].to] = i;
                    }
                }
            } else {
                que.assign(1, s);
                vector <bool> in_queue(n, false);
                in_queue[s] = true;
                for (int b = 0; b < (int)que.size(); b++) {
                    int u = que[b];
                    in_queue[u] = false;
                    for (int i = head[u]; i != -1; i = edges[i].nxt) if (edges[i].cap != edges[i].flow && pot[u] + edges[i].cost < pot[edges[i].to]) {
                        pot[edges[i].to] = pot[u] + edges[i].cost;
                        trace[edges[i].to] = i;
                        if (!in_queue[edges[i].to]) {
                            que.push_back(edges[i].to);
                            in_queue[edges[i].to] = true;
                        }
                    }
                }
            }
        }
        while (pot[t] < inf_cost) {
            Cap push = inf_cap;
            for (int u = t; u != s; u = edges[trace[u]].from)
                push = min(push, edges[trace[u]].cap - edges[trace[u]].flow);
            for (int u = t; u != s; u = edges[trace[u]].from) {
                edges[trace[u]].flow += push;
                edges[trace[u] ^ 1].flow -= push;
            }
            flow += push; cost += push * pot[t];
            expath(s);
        }
        return {flow, cost};
    }
};
template <bool ToShuffle = false> struct MaxMatching {
    int n;
    vector <int> match, gr, cnt;
    vector <pair <int, int>> edg;
    MaxMatching(int n = 0): n(n) {}
    void add(int u, int v) { edg.emplace_back(u, v); }
    struct Data {
        int used, prev, root, depth;
        Data(int used, int prev, int root, int depth): used(used), prev(prev), root(root), depth(depth) {}
    };
    vector <pair <int, int>> max_matching() {
        if constexpr (ToShuffle) {
            mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
            shuffle(edg.begin(), edg.end(), rng);
        }
        match.assign(n, -1);
        gr.resize(edg.size() << 1);
        cnt.assign(n + 1, 0);
        for (auto [u, v]: edg) ++cnt[u], ++cnt[v];
        for (int i = 0, c = 0; i <= n; ++i) c += cnt[i], cnt[i] = c;
        for (int i = edg.size(); i-- > 0; ) {
            auto &[u, v] = edg[i];
            gr[--cnt[u]] = v;
            gr[--cnt[v]] = u;
        }
        vector <Data> data(n, Data(0, 0, 0, 0));
        int used_mark = 0, db_ptr, de_ptr;
        vector <int> dq(n);
        while (true) {
            used_mark++; db_ptr = de_ptr = 0;
            for (int i = 0; i < n; ++i) if (match[i] == -1) {
                data[i] = Data(used_mark, -1, i, 0);
                dq[de_ptr++] = i;
            }
            int aug_cnt = 0;
            while (db_ptr < de_ptr) {
                int u = dq[db_ptr++];
                if (match[data[u].root] != -1) continue;
                bool aug_found = false;
                for (int ti = cnt[u]; ti < cnt[u + 1]; ++ti) {
                    int t = gr[ti];
                    if (data[t].used == used_mark && data[t].depth == 0 && match[data[t].root] == -1) {
                        aug_cnt++;
                        match[u] = t, match[t] = u;
                        int len = 1;
                        for (int x = u; data[x].prev != -1; x = data[x].prev) {
                            if (data[x].depth == 1) match[x] = data[x].prev, match[data[x].prev] = x;
                            len++;
                        }
                        for (int x = t; data[x].prev != -1; x = data[x].prev) {
                            if (data[x].depth == 1) match[x] = data[x].prev, match[data[x].prev] = x;
                            len++;
                        }
                        aug_found = true;
                        break;
                    }
                }
                if (aug_found) continue;
                for (int ti = cnt[u]; ti < cnt[u + 1]; ++ti) {
                    int t = gr[ti];
                    if (data[t].used != used_mark) {
                        int t2 = match[t];
                        data[t] = Data(used_mark, u, data[u].root, 1);
                        data[t2] = Data(used_mark, t, data[u].root, 0);
                        dq[de_ptr++] = t2;
                    }
                }
            }
            if (!aug_cnt) break;
        }
        vector <pair <int, int>> res;
        for (int i = 0; i < n; ++i) if (i < match[i]) res.push_back({i, match[i]});
        return res;
    }
    pair <vector <int>, vector <int>> minimum_vertex_cover() {
        vector <int> q(n);
        int qb = 0, qe = 0;
        vector <bool> f(n);
        for (int i = 0; i < n; ++i) if (match[i] == -1) q[qe++] = i;
        while (qb < qe) {
            int u = q[qb++];
            for (int i = cnt[u]; i < cnt[u + 1]; ++i) {
                int v = gr[i];
                if (!f[v]) {
                    f[v] = true;
                    q[qe++] = match[v];
                }
            }
        }
        for (int i = 0; i < n; ++i) if (match[i] != -1 && !f[i] && !f[match[i]]) f[i] = true;
        vector <int> L, R;
        for (int i = 0; i < n; ++i) (f[i] ? L : R).push_back(i);
        return {L, R};
    }
};
template <class T> struct Hungarian {
    int n;
    vector <vector <T>> c;
    vector <T> fx, fy, d;
    vector <int> l, r, arg, trace;
    int start, finish;
    static constexpr T inf = numeric_limits<T>::max() >> 1;
    Hungarian() {}
    Hungarian(int n1, int n2): n(max(n1, n2)), c(n, vector<T>(n, inf)), fx(n), fy(n), d(n), l(n, -1), r(n, -1), arg(n), trace(n) {}
    void add(int u, int v, T cost) { c[u][v] = min(c[u][v], cost); }
    T getC(int u, int v) { return c[u][v] - fx[u] - fy[v]; }
    T max_matching() {
        for (int u = 0; u < n; ++u) {
            fx[u] = c[u][0];
            for (int v = 0; v < n; ++v) fx[u] = min(fx[u], c[u][v]);
        }
        for (int v = 0; v < n; ++v) {
            fy[v] = c[0][v] - fx[0];
            for (int u = 0; u < n; ++u) fy[v] = min(fy[v], c[u][v] - fx[u]);
        }
        vector <int> q(n);
        int qb, qe;
        for (int u = 0; u < n; ++u) {
            start = u;
            qb = qe = 0;
            q[qe++] = start;
            fill(trace.begin(), trace.end(), -1);
            for (int v = 0; v < n; ++v) d[v] = getC(start, v), arg[v] = start;
            finish = -1;
            while (finish == -1) {
                while (qb < qe) {
                    int u = q[qb++];
                    for (int v = 0; v < n; ++v) if (trace[v] == -1) {
                        T w = getC(u, v);
                        if (!w) {
                            trace[v] = u;
                            if (r[v] == -1) {
                                finish = v;
                                goto nxt;
                            }
                            q[qe++] = r[v];
                        }
                        if (d[v] > w) d[v] = w, arg[v] = u;
                    }
                }
                nxt:;
                if (finish == -1) {
                    T delta = inf;
                    for (int v = 0; v < n; ++v) if (trace[v] == -1 && d[v] < delta) delta = d[v];
                    fx[start] += delta;
                    for (int v = 0; v < n; ++v) {
                        if (trace[v] != -1) {
                            int u = r[v];
                            fy[v] -= delta; fx[u] += delta;
                        } else d[v] -= delta;
                    }
                    for (int v = 0; v < n; ++v) if (trace[v] == -1 && !d[v]) {
                        trace[v] = arg[v];
                        if (r[v] == -1) {
                            finish = v;
                            break;
                        }
                        q[qe++] = r[v];
                    }
                }
            }
            do {
                int u = trace[finish], nxt = l[u];
                l[u] = finish; r[finish] = u;
                finish = nxt;
            } while (finish != -1);
        }
        T ans = 0;
        for (int i = 0; i < n; ++i) {
            if (c[i][l[i]] != inf) ans += c[i][l[i]];
            else l[i] = -1;
        }
        return ans;
    }
};
} using namespace MAX_FLOW;

void process(void) {
    const int inf = 1e9;
    int w, l, n; cin >> l >> w >> n;
    vector <pair <int, int>> a(n); cin >> a;
    PushRelabel <long long> mf(n + n + 2);
    int s = n + n, t = n + n + 1;
    for (int i = 0; i < n; ++i) {
        if (a[i].se <= 100) {
            mf.add(s, i, inf);
        }
        if (a[i].se >= w - 100) {
            mf.add(i + n, t, inf);
        }
        mf.add(i, i + n, 1);
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i != j) {
        if (1LL * (a[i].fi - a[j].fi) * (a[i].fi - a[j].fi) + 1LL * (a[i].se - a[j].se) * (a[i].se - a[j].se) <= 40000) {
            mf.add(i + n, j, inf);
        }
    }
    cout << mf.max_flow(s, t) << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    file("test");
    // int t; cin >> t; while (t--)
    process();
    return (0^0);
}

