
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& vis,
             vector<vector<char>>& board,
             int dr[], int dc[]) {

        int n = board.size();
        int m = board[0].size();

        vis[r][c] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] && board[nr][nc] == 'O') {
                dfs(nr, nc, vis, board, dr, dc);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board) {

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        // Top & Bottom boundary
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, vis, board, dr, dc);

            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, vis, board, dr, dc);
        }

        // Left & Right boundary
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, vis, board, dr, dc);

            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, vis, board, dr, dc);
        }

        // Flip surrounded regions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        return board;
    }
};

int main() {

    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };

    Solution obj;
    auto ans = obj.fill(board.size(), board[0].size(), board);

    for (auto &row : ans) {
        for (auto &ch : row)
            cout << ch << " ";
        cout << "\n";
    }

    return 0;
}
