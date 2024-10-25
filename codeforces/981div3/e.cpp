#include <bits/stdc++.h>
using namespace std;

// Định nghĩa hàm băm tùy chỉnh cho vector<int>
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

// Hàm kiểm tra xem một hoán vị có đơn giản không
bool isSimple(const vector<int>& p, int n) {
    for (int i = 1; i <= n; ++i) {
        if (p[i] != i && p[p[i]] != i) {
            return false;
        }
    }
    return true;
}

// Hàm giải quyết bài toán
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        // Nếu hoán vị đã đơn giản
        if (isSimple(p, n)) {
            cout << 0 << '\n';
            continue;
        }

        // Sử dụng BFS với tối ưu hóa
        queue<pair<vector<int>, int>> q;  // (hoán vị, số lần hoán đổi)
        unordered_set<vector<int>, VectorHash> visited;  // Lưu trạng thái đã xét bằng unordered_set<vector<int>, VectorHash>
        q.push({p, 0});
        visited.insert(p);  // Lưu trữ trực tiếp vector<int>

        int result = -1;

        while (!q.empty()) {
            auto [current_perm, steps] = q.front();
            q.pop();

            // Duyệt qua các vị trí chưa đúng
            vector<int> mismatch;
            for (int i = 1; i <= n; ++i) {
                if (current_perm[i] != i) {
                    mismatch.push_back(i);
                }
            }

            // Thử hoán đổi các phần tử trong tập mismatch
            for (int i = 0; i < mismatch.size(); ++i) {
                for (int j = i + 1; j < mismatch.size(); ++j) {
                    vector<int> new_perm = current_perm;
                    swap(new_perm[mismatch[i]], new_perm[mismatch[j]]);  // Hoán đổi

                    // Kiểm tra nếu trạng thái mới đã là hoán vị đơn giản
                    if (isSimple(new_perm, n)) {
                        result = steps + 1;
                        break;
                    }

                    // Thêm trạng thái mới vào hàng đợi nếu chưa xét
                    if (visited.find(new_perm) == visited.end()) {
                        visited.insert(new_perm);
                        q.push({new_perm, steps + 1});
                    }
                }
                if (result != -1) break;
            }
            if (result != -1) break;
        }

        cout << result << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
