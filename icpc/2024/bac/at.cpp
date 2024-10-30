// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <limits>

// using namespace std;

// int findMinHeightSum(int n, int D, int H, const vector<int>& heights) {
//     vector<int> dp(n, numeric_limits<int>::max());
//     dp[0] = heights[0];  // Chiều cao ban đầu từ cọc đầu tiên
    
//     // Duyệt qua các cọc từ 1 đến n-1
//     for (int i = 1; i < n; ++i) {
//         // Xét các cọc trước đó trong phạm vi D
//         for (int j = max(0, i - D); j < i; ++j) {
//             // Kiểm tra điều kiện chênh lệch chiều cao
//             if (abs(heights[i] - heights[j]) <= H) {
//                 // Cập nhật dp[i] nếu tìm thấy tổng chiều cao nhỏ hơn
//                 dp[i] = min(dp[i], dp[j] + heights[i]);
//             }
//         }
//     }
    
//     // Kiểm tra kết quả tại cọc cuối
//     return dp[n - 1] == numeric_limits<int>::max() ? -1 : dp[n - 1];
// }

// int main() {
//     int n, D, H;
//     cin >> n >> D >> H;
//     vector<int> heights(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> heights[i];
//     }
    
//     int result = findMinHeightSum(n, D, H, heights);
//     cout << result << endl;
    
//     return 0;
// }

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <limits>

using namespace std;

int findMinHeightSum(int n, int D, int H, const vector<int>& heights) {
    vector<int> dp(n, numeric_limits<int>::max());
    dp[0] = heights[0];  
    
    deque<int> dq; 
    dq.push_back(0);  
    
    for (int i = 1; i < n; ++i) {
        while (!dq.empty() && i - dq.front() > D) {
            dq.pop_front();
        }
        if (!dq.empty()) {
            dp[i] = dp[dq.front()] + heights[i];
        }
        while (!dq.empty() && dp[i] <= dp[dq.back()]) {
            dq.pop_back();
        }
        if (!dq.empty() && abs(heights[i] - heights[dq.back()]) <= H) {
            dq.push_back(i);
        }
    }
    return dp[n - 1] == numeric_limits<int>::max() ? -1 : dp[n - 1];
}

int main() {
    int n, D, H;
    cin >> n >> D >> H;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    
    int result = findMinHeightSum(n, D, H, heights);
    cout << result << endl;
    
    return 0;
}
