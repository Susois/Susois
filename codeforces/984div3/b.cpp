#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    vector<int> se(k, 0);
    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        se[u - 1] += v;
    }
    sort(se.rbegin(), se.rend());
    for (int i = 0; i < min(n, k); i++)
    {
        sum += se[i];
    }
    cout << sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//   int n, k;
//   cin >> n >> k;
//   vector<int> brand_cost(k, 0);
//   for (int i = 0; i < k; i++) {
//     int b, c;
//     cin >> b >> c;
//     brand_cost[b - 1] += c;
//   }
//   sort(brand_cost.rbegin(), brand_cost.rend());
//   long long ans = 0;
//   for (int i = 0; i < min(n, k); i++) {
//     ans += brand_cost[i];
//   }
//   cout << ans << '\n';
// }

// int main() {
//   int t;
//   cin >> t;
//   while (t--) {
//     solve();
//   }
//   return 0;
// }