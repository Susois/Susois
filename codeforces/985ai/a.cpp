#include<iostream>
using namespace std;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int cnt = 0;
    int s= m/k;
    cnt = s-n>=0 ? s-n+1 : 0;
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}



