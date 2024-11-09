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

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ones;
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones.emplace_back(i - last);
            last = i + 1;
        }
    }
    ones.emplace_back(n - last);
    int m = ones.size();
    vector<int> pref(m + 1);
    for (int i = 0; i < m; i++) pref[i + 1] = pref[i] + ones[i];
    int res = ones.size() - 1;
    for (int i = 1; i <= n; i++) {
        int cur = 0, j = 0;
        // pref[k] - pref[j] >= i;
        int cnt = 0;
        while (true) {
            int x = lower_bound(pref.begin(), pref.end(), i + pref[j]) - pref.begin();
            if (x == m + 1) break;
            cnt++;
            j = x;
        }
        if (cnt > 1) res = max(res, cnt * i + cnt - 1);
    }
    cout << res;
}

