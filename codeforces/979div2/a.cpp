#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMaxScore(vector<int>& a, int n) {
    // Tìm phần tử nhỏ nhất và lớn nhất trong mảng a
    int min_a = *min_element(a.begin(), a.end());
    int max_a = *max_element(a.begin(), a.end());
    
    // Tính tổng chênh lệch c[i] - b[i] qua tất cả các phần tử
    return (max_a - min_a) * (n - 1);
}

int main() {
    int t;
    cin >> t;  // Số lượng test cases
    
    while (t--) {
        int n;
        cin >> n;  // Kích thước của mảng
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];  // Nhập các phần tử của mảng a
        }
        
        // Tính điểm số tối đa
        int result = getMaxScore(a, n);
        
        // In ra kết quả
        cout << result << endl;
    }

    return 0;
}
