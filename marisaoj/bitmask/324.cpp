#include <iostream>
#include <vector>
using namespace std;

bool is_safe(int x, int y, vector<vector<int>>& board) {
    return x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == -1;
}

void print_solution(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell+1 << "   ";
        }
        cout << endl;
    }
}

bool solve(int x, int y, int move_count, vector<vector<int>>& board, const vector<pair<int, int>>& moves) {
    if (move_count == board.size() * board[0].size()) return true;

    for (const auto& [dx, dy] : moves) {
        int nx = x + dx, ny = y + dy;
        if (is_safe(nx, ny, board)) {
            board[nx][ny] = move_count;
            if (solve(nx, ny, move_count + 1, board, moves)) return true;
            board[nx][ny] = -1;
        }
    }

    return false;
}

void knight_tour(int n, int m) {
    vector<vector<int>> board(n, vector<int>(m, -1));
    vector<pair<int, int>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    board[0][0] = 0;
    if (!solve(0, 0, 1, board, moves)) {
        cout << "No solution exists." << endl;
    } else {
        print_solution(board);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    knight_tour(n, m);
    return 0;
}
