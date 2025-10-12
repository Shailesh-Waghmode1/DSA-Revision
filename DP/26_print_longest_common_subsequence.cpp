/*
------------------------------------------------------------
🧩 Problem: DP-26 | Print Longest Common Subsequence
🎯 Objective: Print the actual LCS string, not just its length.

Example:
Input:  s1 = "abcde", s2 = "bdgek"
Output: "bde"

------------------------------------------------------------
💡 Intuition / Steps:
1️⃣ Build DP table for LCS length (same as standard LCS problem).
2️⃣ From dp[n][m], backtrack:
    - If s1[i-1] == s2[j-1], it’s part of LCS → add it to answer.
    - Else move in direction of the larger dp value (up or left).
3️⃣ Reverse the collected characters (since we traverse backwards).

------------------------------------------------------------
⏱️ Time Complexity: O(N*M)
💾 Space Complexity: O(N*M)
------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printLCS(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Step 1: Create DP table initialized with -1
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Step 2: Base initialization (0 for empty substrings)
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= m; j++) dp[0][j] = 0;

    // Step 3: Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Step 4: Reconstruct the LCS from dp[n][m]
    int len = dp[n][m];
    string lcs(len, '$'); // dummy chars to fill initially
    int i = n, j = m, index = len - 1;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[index] = s1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "The Longest Common Subsequence is: " << lcs << endl;
}

int main() {
    string s1 = "abcde";
    string s2 = "bdgek";

    printLCS(s1, s2);

    return 0;
}
