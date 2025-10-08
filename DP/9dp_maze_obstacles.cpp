#include <iostream>
#include <vector>
using namespace std;

/*
------------------------------------------------------------
🧩 Problem: Grid Unique Paths II (DP 9)

🧠 Description:
We are given an “N*M” grid (maze) where:
- 0 → open cell (movement allowed)
- -1 → blocked cell (no movement)

We must count all *unique paths* from top-left (0,0)
to bottom-right (n-1,m-1). Movement is allowed only:
   → right or ↓ down

------------------------------------------------------------
📘 Intuition / Steps:

1️⃣ **If a cell is blocked (-1)** → no path passes through it.
2️⃣ **Base case:** Start (0,0) has 1 path if not blocked.
3️⃣ **Recurrence:** 
       dp[i][j] = dp[i-1][j] + dp[i][j-1]
   (paths from top + paths from left)
4️⃣ **Goal:** dp[n-1][m-1] = total unique paths to destination.
5️⃣ **Use DP** to store intermediate results efficiently
   and avoid recomputation.

------------------------------------------------------------
📊 Example Grid (3x3):

   [0][0][0]
   [0][-1][0]
   [0][0][0]

Possible paths:
   →→↓↓, ↓→→↓, ↓→↓→
   (3 unique ways to reach end avoiding the obstacle)

------------------------------------------------------------
💡 Approaches:

1️⃣ Memoization (Top-Down)
2️⃣ Tabulation (Bottom-Up)
3️⃣ Space Optimized DP

------------------------------------------------------------
⏱️ Time & Space Complexities:

Approach 1: Memoization
   Time  → O(N*M)
   Space → O(N*M) + O(N+M) (recursion + dp table)

Approach 2: Tabulation
   Time  → O(N*M)
   Space → O(N*M)

Approach 3: Space Optimized
   Time  → O(N*M)
   Space → O(M)

------------------------------------------------------------
*/

// ✅ Approach 1: Memoization
int mazeObstaclesMemo(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp) {
    if (i >= 0 && j >= 0 && maze[i][j] == -1) return 0;
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int up = mazeObstaclesMemo(i - 1, j, maze, dp);
    int left = mazeObstaclesMemo(i, j - 1, maze, dp);

    return dp[i][j] = up + left;
}

int mazeObstacles_Memoization(int n, int m, vector<vector<int>> &maze) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return mazeObstaclesMemo(n - 1, m - 1, maze, dp);
}

// ✅ Approach 2: Tabulation
int mazeObstacles_Tabulation(int n, int m, vector<vector<int>> &maze) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0, left = 0;
            if (i > 0) up = dp[i - 1][j];
            if (j > 0) left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }
    return dp[n - 1][m - 1];
}

// ✅ Approach 3: Space Optimized
int mazeObstacles_SpaceOptimized(int n, int m, vector<vector<int>> &maze) {
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == -1) {
                temp[j] = 0;
                continue;
            }
            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }

            int up = 0, left = 0;
            if (i > 0) up = prev[j];
            if (j > 0) left = temp[j - 1];

            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[m - 1];
}

// 🧪 Main Function to test all approaches
int main() {
    vector<vector<int>> maze = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    int n = maze.size();
    int m = maze[0].size();

    cout << "Memoization: " << mazeObstacles_Memoization(n, m, maze) << endl;
    cout << "Tabulation: " << mazeObstacles_Tabulation(n, m, maze) << endl;
    cout << "Space Optimized: " << mazeObstacles_SpaceOptimized(n, m, maze) << endl;

    return 0;
}
