#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;

        int c = 0;
        for (int i = 0; i < 5; ++i) {
            c |= ((a ^ b) & (1 << i));
        }
        for (int i = 5; i < 10; ++i) {
            c |= ((a & b) & (1 << i));
        }
        for (int i = 10; i < 15; ++i) {
            c |= ((a | b) & (1 << i));
        }

        cout << c << "\n";
    }

    return 0;
}
