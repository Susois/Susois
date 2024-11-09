
#include<bits/stdc++.h>
using namespace std;

// Function to calculate the number of multiples of `x` in range [l, r]
int countMultiples(int l, int r, int x) {
    return r / x - (l - 1) / x;
}

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    
    // If k == 1, we can always pick every number individually
    if (k == 1) {
        cout << r - l + 1 << '\n';
        return;
    }

    int operations = 0;

    // Iterate over all possible divisors starting from l to sqrt(r) (to reduce time complexity)
    for (int x = 2; x * x <= r; x++) {
        int multiples = countMultiples(l, r, x);
        if (multiples >= k) {
            operations++;
        }
    }
    
    // For larger numbers, we need to count only the multiples directly
    // Iterate from sqrt(r) + 1 to r, as large numbers may have fewer multiples.
    for (int x = max(l, (int)sqrt(r)); x <= r; x++) {
        int multiples = countMultiples(l, r, x);
        if (multiples >= k) {
            operations++;
        }
    }

    cout << operations << '\n';
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
