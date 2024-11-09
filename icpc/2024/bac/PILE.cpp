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

    int n, d, h;
    cin >> n >> d >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int64_t> dp(n, 1e18);
    dp[0] = a[0];
    for (int i = 0; i < n; i++) {
        if (dp[i] == 1e18) continue;
        for (int j = i + 1; j < n; j++) {
            if (j - i <= d && abs(a[i] - a[j]) <= h) {
                dp[j] = min(dp[j], dp[i] + a[j]);
            }
        }
    }
    cout << (dp.back() == 1e18 ? -1 : dp.back());
}
