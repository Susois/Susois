#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        // Count the number of '0's in the string
        int zeroCount = count(s.begin(), s.end(), '0');
        
        // Alice wins if the number of '0's is odd, otherwise Bob wins
        if (zeroCount % 2 == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
