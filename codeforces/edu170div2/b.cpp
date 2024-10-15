#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX_N = 1000;

vector<vector<int>> computeBinomialCoefficients(int max_n) {
    vector<vector<int>> C(max_n + 1, vector<int>(max_n + 1, 0));
    for (int n = 0; n <= max_n; ++n) {
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; ++k) {
            C[n][k] = (C[n][k - 1] + C[n - 1][k - 1]) % MOD;
        }
    }
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<int> n_values(t);
    vector<int> k_values(t);
    for (int i = 0; i < t; ++i) {
        cin >> n_values[i];
    }
    for (int i = 0; i < t; ++i) {
        cin >> k_values[i];
    }

    int max_n = *max_element(n_values.begin(), n_values.end());
    vector<vector<int>> C = computeBinomialCoefficients(max_n);

    for (int i = 0; i < t; ++i) {
        int n = n_values[i];
        int k = k_values[i];
        cout << C[n][k] << "\n";
    }

    return 0;
}
