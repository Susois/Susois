#include<bits/stdc++.h>
using namespace std;

int n, m, Count = 0; 
char matrix[11][1001]; 
bool Visit[11][1001]; 
void colorr(int row, int col) {
    for (int j = col; j < m && matrix[row][j] == '#'; ++j) {
        if (!Visit[row][j]) {
            Visit[row][j] = true;
        }
    }
}

void colorc(int row, int col) {
    for (int i = row; i < n && matrix[i][col] == '#'; ++i) {
        if (!Visit[i][col]) {
            Visit[i][col] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(Visit, false, sizeof(Visit)); 
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '#' && !Visit[i][j]) {
                Count++;
                #include<bits/stdc++.h>
using namespace std;

int n, m, Count = 0; 
char matrix[11][1001]; 
bool Visit[11][1001];

// Hàm tô màu theo hàng
void colorr(int row, int col) {
    for (int j = col; j < m && matrix[row][j] == '#'; ++j) {
        Visit[row][j] = true;
    }
}

// Hàm tô màu theo cột
void colorc(int row, int col) {
    for (int i = row; i < n && matrix[i][col] == '#'; ++i) {
        Visit[i][col] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(Visit, false, sizeof(Visit));  // Khởi tạo mảng đã thăm là false
    cin >> n >> m;  // Đọc kích thước ma trận

    // Nhập ma trận
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Duyệt qua toàn bộ ma trận
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '#' && !Visit[i][j]) {
                Count++;  // Tăng số lần tô màu

                // Tính toán số lượng `#` liên tiếp trong hàng và cột cùng lúc tô màu
                int r = 0, c = 0;

                // Đếm số `#` liên tiếp theo hàng
                for (int k = j; k < m && matrix[i][k] == '#'; ++k) {
                    r++;
                }
                
                // Đếm số `#` liên tiếp theo cột
                for (int k = i; k < n && matrix[k][j] == '#'; ++k) {
                    c++;
                }

                // Tô màu theo hướng có nhiều `#` liên tiếp hơn
                if (r >= c) {
                    colorr(i, j);  // Tô theo hàng
                } else {
                    colorc(i, j);  // Tô theo cột
                }
            }
        }
    }

    // Xuất kết quả
    cout << Count << endl;

    return 0;
}

                int r = 0, c = 0;

                for (int k = j; k < m && matrix[i][k] == '#'; ++k) {
                    r++;
                }
                for (int k = i; k < n && matrix[k][j] == '#'; ++k) {
                    c++;
                }
                if (r >= c) {
                    colorr(i, j);
                } else {
                    colorc(i, j); 
                }
            }
        }
    }

    cout << Count << endl;

    return 0;
}
