/*
------------------------------------------------------------
🧩 Problem: DP-27 | Longest Common Substring
🎯 Objective: Find the length of the longest common substring between two strings.

📘 Definition:
A *substring* is a contiguous sequence of characters within a string.
Unlike subsequence, all characters must appear consecutively.

Example:
Input:
    s1 = "abcjklp"
    s2 = "acjkp"
Output:
    3
Explanation:
    The longest common substring is "cjk", having length 3.

------------------------------------------------------------
💡 Approaches Covered:
1️⃣ Recursion + Memoization (top-down)
2️⃣ Tabulation (Bottom-Up DP)
3️⃣ Space Optimization (O(M))

------------------------------------------------------------
⏱️ Time Complexity:
  ➤ Memoization: O(N*M)
  ➤ Tabulation: O(N*M)
  ➤ Space Optimized: O(N*M)

💾 Space Complexity:
  ➤ Memoization: O(N*M) + O(N+M) (recursion stack)
  ➤ Tabulation: O(N*M)
  ➤ Space Optimized: O(M)
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/////////////////////////////////////////////////////////////
// 1️⃣ MEMOIZATION (TOP-DOWN)
/////////////////////////////////////////////////////////////

int ans = 0; // global variable to track max substring length

int solveMemo(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
    if (i == 0 || j == 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + solveMemo(s1, s2, i - 1, j - 1, dp);
        ans = max(ans, dp[i][j]);
    } else {
        dp[i][j] = 0; // substring breaks here
        solveMemo(s1, s2, i - 1, j, dp);
        solveMemo(s1, s2, i, j - 1, dp);
    }

    return dp[i][j];
}

int longestCommonSubstringMemo(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    ans = 0; // reset before call
    solveMemo(s1, s2, n, m, dp);
    return ans;
}

/////////////////////////////////////////////////////////////
// 2️⃣ TABULATION (BOTTOM-UP DP)
/////////////////////////////////////////////////////////////

int longestCommonSubstringTab(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = 0;

    // Base Initialization
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= m; j++) dp[0][j] = 0;

    // DP Computation
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

/////////////////////////////////////////////////////////////
// 3️⃣ SPACE OPTIMIZATION (TWO ROWS)
/////////////////////////////////////////////////////////////

int longestCommonSubstringSpaceOpt(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cur[j] = 1 + prev[j - 1];
                ans = max(ans, cur[j]);
            } else {
                cur[j] = 0;
            }
        }
        prev = cur;
    }

    return ans;
}

/////////////////////////////////////////////////////////////
// 🧠 DRIVER FUNCTION
/////////////////////////////////////////////////////////////

int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";

    cout << "Longest Common Substring (Memoization): "
         << longestCommonSubstringMemo(s1, s2) << endl;

    cout << "Longest Common Substring (Tabulation): "
         << longestCommonSubstringTab(s1, s2) << endl;

    cout << "Longest Common Substring (Space Optimized): "
         << longestCommonSubstringSpaceOpt(s1, s2) << endl;

    return 0;
}
