#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<long long, vector<pair<int, int>>> and_map;
    long long count = 0;

    // Generate all pairs (i, j) and store their AND result in a map
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            long long and_result = a[i] & a[j];
            and_map[and_result].emplace_back(i + 1, j + 1);
        }
    }

    // Iterate through (p, q) and check against stored pairs (i, j)
    for (long long p = 0; p < n; p++) {
        for (long long q = 0; q < n; q++) {
            long long pq_result = a[p] & a[q];
            for (const auto& [i, j] : and_map[0]) {  // Directly access pairs with AND result 0
                if ((pq_result & a[i - 1] & a[j - 1]) == 0) {
                    count++;
                    if (count == k) {
                        cout << i << " " << j << " " << p + 1 << " " << q + 1 << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
