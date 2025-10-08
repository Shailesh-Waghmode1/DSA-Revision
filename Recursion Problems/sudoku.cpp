#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Sudoku Solver
    ----------------------
    Given a partially filled 9x9 Sudoku board, fill it so that each row, column, 
    and 3x3 subgrid contains digits 1-9 without repetition.
    
    Approach: Backtracking
    - For each empty cell, try digits 1-9.
    - Check if placing a digit is valid using isValid().
    - Recursively try to fill the next cell.
    - Backtrack if no valid digit leads to a solution.
*/

bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;               // check column
        if (board[row][i] == c) return false;               // check row
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] == c)  // check 3x3 subgrid
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.';  // backtrack
                    }
                }
                return false; // no valid digit found
            }
        }
    }
    return true; // all cells filled
}

int main() {
    vector<vector<char>> board = {
        {'9','5','7','.','1','3','.','8','4'},
        {'4','8','3','.','5','7','1','.','6'},
        {'.','1','2','.','4','9','5','3','7'},
        {'1','7','.','3','.','4','9','.','2'},
        {'5','.','4','9','7','.','3','6','.'},
        {'3','.','9','5','.','8','7','.','1'},
        {'8','4','5','7','9','.','6','1','3'},
        {'.','9','1','.','3','6','.','7','5'},
        {'7','.','6','1','8','5','4','.','9'}
    };

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
