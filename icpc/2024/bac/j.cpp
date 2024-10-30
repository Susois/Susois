#include <bits/stdc++.h>
using namespace std;

struct Sensor {
    int x, y;
};

// Hàm kiểm tra khoảng cách giữa hai cảm biến
bool areOverlapping(const Sensor& a, const Sensor& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy <= 200 * 200;
}

// Hàm DFS để tìm các thành phần liên thông
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

// Hàm kiểm tra nếu có một thành phần liên thông chạm cả biên trái và biên phải
bool canPassWithoutDestroying(vector<Sensor>& sensors, int L, int W) {
    int n = sensors.size();
    vector<int> left, right;

    // Tìm các cảm biến chạm vào biên trái và biên phải
    for (int i = 0; i < n; i++) {
        if (sensors[i].x <= 100) left.push_back(i);
        if (sensors[i].x >= L - 100) right.push_back(i);
    }

    // Xây dựng đồ thị với các cạnh là các cảm biến chồng lấn
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (areOverlapping(sensors[i], sensors[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // Kiểm tra nếu có thành phần liên thông chạm cả biên trái và biên phải
    vector<bool> visited(n, false);
    for (int i : left) {
        if (!visited[i]) {
            // Tìm tất cả các cảm biến trong thành phần liên thông với i
            dfs(i, adj, visited);

            // Kiểm tra xem thành phần này có chạm vào biên phải không
            for (int j : right) {
                if (visited[j]) return false;
            }
        }
    }

    return true;
}

// Hàm tìm số lượng cảm biến tối thiểu cần phá hủy
int minSensorsToDestroy(vector<Sensor>& sensors, int L, int W) {
    int left = 0, right = sensors.size(), result = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        // Tạo danh sách các cảm biến còn lại sau khi phá hủy `mid` cảm biến đầu tiên
        vector<Sensor> remainingSensors(sensors.begin() + mid, sensors.end());

        if (canPassWithoutDestroying(remainingSensors, L, W)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int L, W, N;
    cin >> L >> W >> N;
    vector<Sensor> sensors(N);

    for (int i = 0; i < N; ++i) {
        cin >> sensors[i].x >> sensors[i].y;
    }

    // Kiểm tra nếu có đường đi an toàn mà không cần phá hủy
    if (canPassWithoutDestroying(sensors, L, W)) {
        cout << 0 << endl;
    } else {
        // Tìm số lượng cảm biến tối thiểu cần phá hủy
        int result = minSensorsToDestroy(sensors, L, W);
        cout << result << endl;
    }

    return 0;
}
