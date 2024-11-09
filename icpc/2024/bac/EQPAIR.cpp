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

void process(void) {
    int n; cin >> n;
    vector <int> a(n); cin >> a;
    vector <int> cnt(int(1e6) + 1);
    long long res = 0;
    for (int x: a) {
        res += cnt[x];
        ++cnt[x];
    }
    cout << res << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    file("test");
    // int t; cin >> t; while (t--)
    process();
    return (0^0);
}

