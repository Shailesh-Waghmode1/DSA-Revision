#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    N-Queens Problem: Two Approaches
    ---------------------------------

    1. Standard Backtracking:
       - Check isSafe(row, col) by scanning row and diagonals.
       - Time Complexity: O(N! * N)
       - Space Complexity: O(N^2) board + O(N) recursion stack

    2. Optimized Backtracking (using hashing for rows and diagonals):
       - Use 3 arrays:
           leftRow[row], upperDiagonal[n-1 + col - row], lowerDiagonal[row + col]
       - Check safety in O(1) time
       - Time Complexity: O(N!) (much faster than standard)
       - Space Complexity: O(N^2) board + O(N) recursion stack + O(N) for arrays
*/

class Solution {
public:
    // ------------------- Approach 1: Standard isSafe -------------------
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int r = row, c = col;
        // Upper-left diagonal
        while (r >= 0 && c >= 0) if (board[r--][c--] == 'Q') return false;
        // Left row
        r = row; c = col;
        while (c >= 0) if (board[r][c--] == 'Q') return false;
        // Lower-left diagonal
        r = row; c = col;
        while (r < n && c >= 0) if (board[r++][c--] == 'Q') return false;
        return true;
    }

    void solveStandard(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solveStandard(col + 1, board, ans, n);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueensStandard(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solveStandard(0, board, ans, n);
        return ans;
    }

    // ------------------- Approach 2: Optimized with hashing -------------------
    void solveOptimized(int col, vector<string> &board, vector<vector<string>> &ans,
                        vector<int> &leftRow, vector<int> &upperDiagonal,
                        vector<int> &lowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solveOptimized(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = '.'; // backtrack
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueensOptimized(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solveOptimized(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};

// ------------------------- MAIN FUNCTION -------------------------
int main() {
    int n = 4; // Example 4x4 board
    Solution obj;

    cout << "----- Standard Approach -----\n";
    vector<vector<string>> ansStandard = obj.solveNQueensStandard(n);
    for (int i = 0; i < ansStandard.size(); i++) {
        cout << "Arrangement " << i + 1 << ":\n";
        for (int j = 0; j < n; j++) cout << ansStandard[i][j] << endl;
        cout << endl;
    }

    cout << "----- Optimized Approach -----\n";
    vector<vector<string>> ansOptimized = obj.solveNQueensOptimized(n);
    for (int i = 0; i < ansOptimized.size(); i++) {
        cout << "Arrangement " << i + 1 << ":\n";
        for (int j = 0; j < n; j++) cout << ansOptimized[i][j] << endl;
        cout << endl;
    }

    return 0;
}
