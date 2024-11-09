#include <bits/stdc++.h>

using namespace std;

#define                  fi  first
#define                  se  second
#define                left  ___left
#define               right  ___right
#define                TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define             MASK(i)  (1LL << (i))
#define           BIT(x, i)  ((x) >> (i) & 1)
#define  __builtin_popcount  __builtin_popcountll
#define              ALL(v)  (v).begin(), (v).end()
#define           REP(i, n)  for (int i = 0, _n = (n); i < _n; ++i)
#define          REPD(i, n)  for (int i = (n); i-- > 0; )
#define        FOR(i, a, b)  for (int i = (a), _b = (b); i < _b; ++i) 
#define       FORD(i, b, a)  for (int i = (b), _a = (a); --i >= _a; ) 
#define       FORE(i, a, b)  for (int i = (a), _b = (b); i <= _b; ++i) 
#define      FORDE(i, b, a)  for (int i = (b), _a = (a); i >= _a; --i) 
#define        scan_op(...)  istream & operator >> (istream &in, __VA_ARGS__ &u)
#define       print_op(...)  ostream & operator << (ostream &out, const __VA_ARGS__ &u)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }
#define DB(...) 23
#define db(...) 23
#define debug(...) 23

template <class U, class V> scan_op(pair <U, V>)  { return in >> u.first >> u.second; }
template <class T> scan_op(vector <T>)  { for (size_t i = 0; i < u.size(); ++i) in >> u[i]; return in; }
template <class U, class V> print_op(pair <U, V>)  { return out << '(' << u.first << ", " << u.second << ')'; }
template <size_t i, class T> ostream & print_tuple_utils(ostream &out, const T &tup) { if constexpr(i == tuple_size<T>::value) return out << ")";  else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); }
template <class ...U> print_op(tuple<U...>) { return print_tuple_utils<0, tuple<U...>>(out, u); }
template <class Con, class = decltype(begin(declval<Con>()))> typename enable_if <!is_same<Con, string>::value, ostream&>::type operator << (ostream &out, const Con &con) { out << '{'; for (__typeof(con.begin()) it = con.begin(); it != con.end(); ++it) out << (it == con.begin() ? "" : ", ") << *it; return out << '}'; }
template <class InIter, class OutIter>  void compress(InIter first, InIter last, OutIter result) { vector <__typeof(*first)> v(first, last); sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); while (first != last) { *result = lower_bound(v.begin(), v.end(), *first) - v.begin() + 1; ++first; ++result; } }

// end of template

const int BLOCK_SIZE = 320;

void process(void) {
    int p, q; string s; cin >> p >> s >> q;
    int n = s.size();
    if (p == 2 || p == 5) {
        vector <int> pos {-1};
        vector <long long> sum {0};
        REP(i, n) if ((s[i] - '0') % p == 0) {
            pos.push_back(i);
            sum.push_back(sum.back() + i);
        }
        while (q--) {
            int l, r; cin >> l >> r; --l;
            int x = lower_bound(ALL(pos), l) - pos.begin();
            int y = lower_bound(ALL(pos), r) - pos.begin() - 1;
            cout << sum[y] - sum[x - 1] - (l - 1) * (y - x + 1) << '\n';
        }
    } else {
        vector <int> pref(n + 1);
        int pw = 1;
        REPD(i, n) {
            pref[i] = (pref[i + 1] + 1LL * (s[i] - '0') * pw) % p;
            pw = pw * 10LL % p;
        }
        compress(ALL(pref), pref.begin());
        ++n;
        vector <int> block_id(n);
        REP(i, n) block_id[i] = i / BLOCK_SIZE;
        int nb = block_id[n - 1] + 1;
        vector <int> left(nb), right(nb);
        REP(i, nb) {
            left[i] = i * BLOCK_SIZE;
            right[i] = min(n, left[i] + BLOCK_SIZE);
        }
        vector cnt_l(nb, vector<long long>(n));
        vector cnt_r(nb, vector<long long>(n));
        vector <int> cnt(n + 1);
        REP(i, nb) {
            FOR(j, left[i], n) cnt_l[i][j] = (j == left[i] ? 0 : cnt_l[i][j - 1]) + cnt[pref[j]]++;
            fill(ALL(cnt), 0);
            REPD(j, i + 1) {
                FORD(k, right[j], left[j]) cnt_r[i][k] = (k == right[j] - 1 ? 0 : cnt_r[i][k + 1]) + cnt[pref[k]]++;
            }
            fill(ALL(cnt), 0);
        }
        while (q--) {
            int l, r; cin >> l >> r; --l;
            long long res = 0;
            if (block_id[l] == block_id[r]) {
                FORE(i, l, r) res += cnt[pref[i]]++;
                FORE(i, l, r) --cnt[pref[i]];
            } else {
                res = cnt_l[block_id[l] + 1][r] + cnt_r[block_id[r] - 1][l];
                FOR(i, l, right[block_id[l]]) ++cnt[pref[i]];
                FORE(i, left[block_id[r]], r) res += cnt[pref[i]];
                FOR(i, l, right[block_id[l]]) --cnt[pref[i]];
            }
            cout << res << '\n';
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); // cout.tie(nullptr);
    file("test");
    // int t; cin >> t; while (t--)
    process();
    // cerr << "Time elapsed: " << TIME << " s.\n";
    return (0^0);
}

