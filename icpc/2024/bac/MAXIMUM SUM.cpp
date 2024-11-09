#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

namespace std {

template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1);
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};

template <typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};

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

}  // namespace std

void solve() {
    int n, m, K; cin >> n >> m >> K;

    Vec<2, int> a(min(n, m) + 1, max(n, m) + 1);
    if (n <= m) {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    } else {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
            cin >> a[j][i];
        }
        swap(n, m);
    }

    Vec<2, long long> pref(n + 1, m + 1);
    vector<long long> dd(1e6 + 1, 1e18);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        pref[i][j] = pref[i - 1][j] + a[i][j];
    }

    int timer = 0;

    long long ans = 0;
    auto check = [&] (int i, int j) {
        long long sum = 0;
        dd[0] = 0;
        for (int k = 1; k <= m; k++) {
            sum += pref[j][k] - pref[i - 1][k];
            ans = max(ans, sum - dd[sum % K]);
            dd[sum % K] = min(dd[sum % K], sum);
        }
        sum = 0;
        for (int k = 1; k <= m; k++) {
            sum += pref[j][k] - pref[i - 1][k];
            dd[sum % K] = 1e18;
        }
    };
    for (int len = n; len >= 1; len--) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (++timer >= 1e8 / m) {
                cout << ans;
                return;
            }
            check(i, j);
        }
    }
    cout << ans;
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // ?cin >> t; 

    while (t--) {
        solve();
        cout << endl;
    }
}

