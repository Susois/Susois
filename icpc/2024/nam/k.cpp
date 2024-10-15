#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct Pacman {
    int u, v, d;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, p, m;
    cin >> n >> p >> m;
    vector<Pacman> pacman(p);

    for (int i = 0; i < p; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        pacman[i] = {u, v, d - 1};  
    }

    for (int i = 0; i < m; ++i) {
        char c;
        int k;
        cin >> c >> k;

        if (c == 'A') {
            for (auto &pac : pacman) {
                int steps = k % n;  
                pac.u = (pac.u + dx[pac.d] * steps + n) % n;
                pac.v = (pac.v + dy[pac.d] * steps + n) % n;
            }
        } else if (c == 'R') {
            for (auto &pac : pacman) {
                pac.d = (pac.d + k) % 4;
            }
        } else if (c == 'Z') {
            int u = k / n;
            int v = k % n;
            for (auto &pac : pacman) {
                pac.u = u;
                pac.v = v;
            }
        }
    }

    for (const auto &pac : pacman) {
        cout << pac.u << " " << pac.v << "\n";
    }

    return 0;
}
