#include <bits/stdc++.h>
using namespace std;

int n, k, target_sum;
vector<int> A, groups;

// Hàm backtracking để thử mọi cách chia dãy
bool backtrack(int index, vector<int>& group_sums) {
    if (index == n) {
        for (int sum : group_sums) {
            if (sum != target_sum) return false;
        }
        return true;
    }

    for (int i = 0; i < k; ++i) {
        if (group_sums[i] + A[index] > target_sum) continue;
        
        group_sums[i] += A[index];
        groups[index] = i + 1;

        if (backtrack(index + 1, group_sums)) return true;

        group_sums[i] -= A[index];
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    A.resize(n);
    groups.resize(n);
    int total_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }

    if (total_sum % k != 0) {
        cout << "ze" << endl;
        return 0;
    }

    target_sum = total_sum / k;
    vector<int> group_sums(k, 0);

    if (backtrack(0, group_sums)) {
        for (int i = 0; i < n; ++i) {
            cout << groups[i] << " ";
        }
        cout << endl;
    } else {
        cout << "ze" << endl;
    }

    return 0;
}
