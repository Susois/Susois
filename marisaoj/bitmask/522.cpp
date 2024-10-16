// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     long long res = 0;
//     vector<int> A(n);
//     unordered_map<int, int> freq;

//     for (int i = 0; i < n; ++i) {
//         cin >> A[i];
//         A[i] ^= i; // A_i = A_i ⊕ i
//         if(freq[A[i]] >= 1)res += freq[A[i]];
//         freq[A[i]]++;
//     }

//     // long long result = 0;
//     // for (const auto &entry : freq) {
//     //     long long count = entry.second;
//     //     result += (count * (count - 1)) / 2; // C(n, 2) = n * (n - 1) / 2
//     // }

//     cout << res << "\n";
//     return 0;
// }
#include <iostream>
#include <unordered_map>
using namespace std;

int count_pairs(int A[], int n) {
    unordered_map<int, int> freq;
    
    // Đếm số lần xuất hiện của mỗi phần tử
    for (int i = 0; i < n; ++i) {
        freq[A[i]]++;
    }
    
    int count = 0;
    // Tính số cặp thỏa mãn
    for (auto it : freq) {
        int val = it.second;
        if (val > 1) {
            count += val * (val - 1) / 2;  // C(k, 2) = k * (k - 1) / 2
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    
    // Nhập mảng
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    // Tính và in ra kết quả
    cout << count_pairs(A, n) << endl;

    return 0;
}
