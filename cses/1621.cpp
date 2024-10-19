#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    set<int> distinct_values;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        distinct_values.insert(x);
    }

    cout << distinct_values.size() << endl;

    return 0;
}
