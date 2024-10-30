#include <bits/stdc++.h>
#define ll long long
#define lli int64_t
#define fi first 
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fint(i,x) for(int i=1;i<=x;i++)
#define fstr(i,s) for(int i=0;i<sz(s);i++)
#define mp make_pair
#define pb push_back
#define vec vector<int> 
#define pii pair<int,int>
#define re return
#define br break
#define fast                        \
ios_base::sync_with_stdio(false);   \
cin.tie(0);cout.tie(0);             
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

    fint(i, n) {
        fint(j, m) {
            cin >> a[i][j];
        }
    }

    fint(i, n) {
        fint(j, m) {
            prefix[i][j] = a[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    int max_sum = -1; 
    fint(r1, n) {
        for (int r2 = r1; r2 <= n; r2++) {
            unordered_map<int, int> summod;
            summod[0] = 0;
            int csum = 0;

            fint(c, m) {
                csum = prefix[r2][c] - prefix[r1 - 1][c];
                int mod = (csum % k + k) % k;

                if (summod.count(mod)) {
                    max_sum = max(max_sum, csum - summod[mod]);
                } else {
                    summod[mod] = csum;
                }
            }
        }
    }

    // Output the result
    cout << (max_sum == -1 ? 0 : max_sum) << endl;
}

int main() {
    fast
    solve();
    return 0;
}
