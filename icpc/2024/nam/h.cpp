#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> matrix;
bool visited[1000][10];

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();

        // Color row
        for (int j = cy; j < m && matrix[cx][j] == '#'; ++j) {
            if (!visited[cx][j]) {
                visited[cx][j] = true;
                q.push({cx, j});
            }
        }
        for (int j = cy; j >= 0 && matrix[cx][j] == '#'; --j) {
            if (!visited[cx][j]) {
                visited[cx][j] = true;
                q.push({cx, j});
            }
        }

        // Color column
        for (int i = cx; i < n && matrix[i][cy] == '#'; ++i) {
            if (!visited[i][cy]) {
                visited[i][cy] = true;
                q.push({i, cy});
            }
        }
        for (int i = cx; i >= 0 && matrix[i][cy] == '#'; --i) {
            if (!visited[i][cy]) {
                visited[i][cy] = true;
                q.push({i, cy});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    matrix.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> matrix[i];
    }

    int actions = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == '#' && !visited[i][j]) {
                bfs(i, j);
                actions++;
            }
        }
    }

    cout << actions << endl;
    return 0;
}
