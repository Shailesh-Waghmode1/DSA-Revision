/*
------------------------------------------------------------
🧩 Problem: DP-25 | Longest Common Subsequence (LCS)
🎯 Category: DP on Strings

📜 Problem Statement:
Given two strings s1 and s2, find the length of their **Longest Common Subsequence (LCS)**.
A *subsequence* of a string is obtained by deleting some (or none) characters without changing 
the relative order of the remaining characters.

Example:
s1 = "acd", s2 = "ced"
LCS = "c" → Length = 1

💡 Intuition / Steps:
1️⃣ Define state:
    dp[i][j] = length of LCS for s1[0..i-1] and s2[0..j-1].

2️⃣ Choice diagram:
    - If characters match: dp[i][j] = 1 + dp[i-1][j-1]
    - Else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])

3️⃣ Base Case:
    - If either string is empty → LCS = 0

4️⃣ Build from smaller subproblems (Recursion → Memoization → Tabulation → Space Optimized).

------------------------------------------------------------
⏱️ Time & Space Complexity:

🔹 Recursion + Memoization:
    Time: O(N*M)
    Space: O(N*M) + O(N+M) (for recursion stack)

🔹 Tabulation:
    Time: O(N*M)
    Space: O(N*M)

🔹 Space Optimization:
    Time: O(N*M)
    Space: O(M)
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// --------------------------------------------------
// Approach 1: Recursion + Memoization
// --------------------------------------------------
int lcsMemoHelper(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
    if (i == 0 || j == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 1 + lcsMemoHelper(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = max(lcsMemoHelper(i - 1, j, s1, s2, dp),
                          lcsMemoHelper(i, j - 1, s1, s2, dp));
}

int lcsMemo(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return lcsMemoHelper(n, m, s1, s2, dp);
}

// --------------------------------------------------
// Approach 2: Tabulation (Bottom-Up)
// --------------------------------------------------
int lcsTab(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Base initialization (consistent with your style)
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= m; j++) dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

// --------------------------------------------------
// Approach 3: Space Optimization
// --------------------------------------------------
int lcsSpaceOpt(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }

    return prev[m];
}

// --------------------------------------------------
// Driver Function
// --------------------------------------------------
int main() {
    string s1 = "acd";
    string s2 = "ced";

    cout << "Recursion + Memoization Result: "
         << lcsMemo(s1, s2) << endl;

    cout << "Tabulation Result: "
         << lcsTab(s1, s2) << endl;

    cout << "Space Optimized Result: "
         << lcsSpaceOpt(s1, s2) << endl;

    return 0;
}

/*
------------------------------------------------------------
✅ Sample Output:
🔹 Recursion + Memoization Result: 1
🔹 Tabulation Result: 1
🔹 Space Optimized Result: 1
------------------------------------------------------------
*/
