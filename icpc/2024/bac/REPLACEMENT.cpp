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
template <class A, class B> bool minimize(A &a, B b)  { return a > b ? a = b, true : false; }
template <class A, class B> bool maximize(A &a, B b)  { return a < b ? a = b, true : false; }
#if __cplusplus < 202002L
    template <class T> int ssize(const T &a) { return a.size(); }
#endif
}

const __int128 inf = __int128(1) << 64;

ostream & operator << (ostream &out, __int128 u) {
    if (!u) return out << 0;
    if (u < 0) return out << '-', operator << (out, -u);
    string s = "";
    while (u) s += char(u % 10 + '0'), u /= 10;
    reverse(s.begin(), s.end());
    return out << s;
}

const int ALPHABET_SIZE = 2;
struct Node {
    int parent, parChar;
    int children[ALPHABET_SIZE];
    int fail, nxt[ALPHABET_SIZE];
    int cnt;
    Node(int parent = -1, int parChar = -1): parent(parent), parChar(parChar) {
        fail = -1;
        cnt = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) children[i] = nxt[i] = -1;
    }
};

vector <Node> nodes;

void addString(const string &s) {
    int p = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        int c = s[i] - '0';
        if (!~nodes[p].children[c]) {
            nodes[p].children[c] = nodes.size();
            nodes.push_back(Node(p, c));
        }
        p = nodes[p].children[c];
    }
    ++nodes[p].cnt;
}

void AC_BFS(void) {
    queue <int> q;
    nodes[0].fail = 0;
    nodes[0].cnt = 0;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (~nodes[0].children[i]) {
            nodes[0].nxt[i] = nodes[0].children[i];
            q.push(nodes[0].children[i]);
        } else nodes[0].nxt[i] = 0;
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        nodes[p].fail = !nodes[p].parent ? 0 : nodes[nodes[nodes[p].parent].fail].nxt[nodes[p].parChar];
        nodes[p].cnt += nodes[nodes[p].fail].cnt;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (~nodes[p].children[i]) {
                nodes[p].nxt[i] = nodes[p].children[i];
                q.push(nodes[p].children[i]);
            } else nodes[p].nxt[i] = nodes[nodes[p].fail].nxt[i];
        }
    }
}

void process(void) {
    int z, n, m; cin >> z >> n >> m;
    vector <vector <int>> a(n);
    vector <int> start;
    for (auto &a: a) {
        int x, k; cin >> x >> k;
        start.push_back(x);
        a.resize(k);
        cin >> a;
    }
    vector <string> s(m);
    nodes.push_back(Node());
    for (auto &s: s) {
        int k; cin >> k;
        while (k--) {
            int x; cin >> x;
            s += char(x + '0');
        }
        addString(s);
    }
    AC_BFS();
    m = nodes.size();
    Vec <__int128, 3> dist(z, m, m, inf), dp(2, m, m, inf);
    for (int turn = 0; turn < n; ++turn) {
        for (int s = 0; s < n; ++s) {
            for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) {
                dp[0][i][j] = dp[1][i][j] = inf;
            }
            for (int i = 0; i < m; ++i) dp[0][i][i] = 0;
            int p = 0;
            for (int x: a[s]) {
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < m; ++j) if (dp[p][i][j] < inf) {
                        if (x < 2 && !nodes[nodes[j].nxt[x]].cnt) {
                            minimize(dp[!p][i][nodes[j].nxt[x]], dp[p][i][j] + 1);
                        }
                        for (int k = 0; k < m; ++k) {
                            minimize(dp[!p][i][k], dp[p][i][j] + dist[x][j][k]);
                        }
                        dp[p][i][j] = inf;
                    }
                }
                p ^= 1;
            }
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    minimize(dist[start[s]][i][j], dp[p][i][j]);
                }
            }
        }
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         // if (dist[3][i][j] < inf) cout << turn << ' ' << i << ' ' << j << ' ' << dist[3][i][j] << '\n';
        //     }
        //     // cout << '\n';
        // }
        // cout << '\n';
    }
    // 11
    for (int s = 2; s < z; ++s) {
        __int128 ans = inf;
        for (int j = 0; j < m; ++j) {
            minimize(ans, dist[s][0][j]);
            // cout << j << ' ' << ans << '\n';
            // if (s == 3 && !dist[s][0][j]) {
            //     cout << "?" << j << ' ' << dist[s][0][j] << '\n';
            // }
        }
        cout << (ans == inf ? 0 : ans) << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    file("test");
    // int t; cin >> t; while (t--)
    process();
    return (0^0);
}

