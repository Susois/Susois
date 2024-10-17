#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool is_safe(const vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; ++i)
        if (board[row][i]) return false;

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j]) return false;

    for (int i = row, j = col; j >= 0 && i < board.size(); ++i, --j)
        if (board[i][j]) return false;

    return true;
}

int solve_nqueens_util(vector<vector<int>>& board, int col) {
    if (col == board.size()) return 1;
    int count = 0;
    for (int i = 0; i < board.size(); ++i) {
        if (is_safe(board, i, col)) {
            board[i][col] = 1;
            count += solve_nqueens_util(board, col + 1);
            board[i][col] = 0;
        }
    }
    return count;
}

int solve_nqueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    return solve_nqueens_util(board, 0);
}

int main() {
    int n;
    cin >> n;
    cout << solve_nqueens(n) << endl;
    return 0;
}
