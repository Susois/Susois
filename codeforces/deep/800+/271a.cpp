#include <bits/stdc++.h>
#define ll long long
#define lli int64_t
#define fi first 
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fint(i, x) for (int i = 1; i <= x; i++)
#define fstr(i, s) for (int i = 0; i < sz(s); i++)
#define mp make_pair
#define pb push_back
#define vec vector<int> 
#define pii pair<int, int>
#define re return
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

bool hasUniqueDigits(int num) {
    string s = to_string(num);
    unordered_set<char> digits;
    for (char ch : s) {
        if (digits.count(ch)) return false;
        digits.insert(ch);
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    int k = n + 1;
    while (true) {
        if (hasUniqueDigits(k)) {
            cout << k;
            break;
        }
        k++;
    }
}

int main() {
    fast
    solve();
    return 0;
}
