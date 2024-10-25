#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;  // Số lượng test cases
    while (t--) {
        int n;
        cin >> n;  // Kích thước của ma trận

        vector<vector<int>> matrix(n, vector<int>(n));

        // Nhập ma trận
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        int total_min_sum = 0;

        // Duyệt qua các đường chéo phía trên và đường chéo chính
        for (int d = 0; d < n; ++d) {
            int min_value = INT_MAX;

            // Tìm min của đường chéo bắt đầu từ (0, d) và kết thúc ở (n-1-d, n-1)
            for (int i = 0; i + d < n; ++i) {
                min_value = min(min_value, matrix[i][i + d]);
            }

            // Nếu min < 0, cộng vào tổng
            if (min_value < 0) {
                total_min_sum += min_value;
            }
        }

        // Duyệt qua các đường chéo phía dưới
        for (int d = 1; d < n; ++d) {
            int min_value = INT_MAX;

            // Tìm min của đường chéo bắt đầu từ (d, 0) và kết thúc ở (n-1, n-1-d)
            for (int i = 0; i + d < n; ++i) {
                min_value = min(min_value, matrix[i + d][i]);
            }

            // Nếu min < 0, cộng vào tổng
            if (min_value < 0) {
                total_min_sum += min_value;
            }
        }

        // In ra giá trị tuyệt đối của tổng các min
        cout << abs(total_min_sum) << endl;
    }

    return 0;
}
