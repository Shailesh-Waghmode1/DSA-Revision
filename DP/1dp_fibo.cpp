#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Fibonacci Number
    -------------------------
    Given an integer n, find the nth Fibonacci number.

    Approaches:
    1. Memoization (Top-Down):
       - Recursively calculate Fibonacci numbers while storing results in dp array.
       - Time Complexity: O(n)
       - Space Complexity: O(n) recursion stack + O(n) dp array

    2. Tabulation (Bottom-Up):
       - Iteratively compute Fibonacci numbers from 0 to n.
       - Time Complexity: O(n)
       - Space Complexity: O(n) dp array

    3. Space Optimization:
       - Only store last two Fibonacci numbers instead of full dp array.
       - Time Complexity: O(n)
       - Space Complexity: O(1)

    Example:
    Input: n = 5
    Output: 5
    Explanation: Fibonacci sequence: 0, 1, 1, 2, 3, 5 ...
*/

int fibMemo(int n, vector<int> &dp) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
}

int fibTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int fibSpaceOpt(int n) {
    if(n == 0) return 0;
    int prev2 = 0, prev = 1;
    for(int i = 2; i <= n; i++) {
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main() {
    int n = 5;

    // Memoization
    vector<int> dp(n+1, -1);
    cout << "Fibonacci (Memoization): " << fibMemo(n, dp) << endl;

    // Tabulation
    cout << "Fibonacci (Tabulation): " << fibTab(n) << endl;

    // Space Optimization
    cout << "Fibonacci (Space Optimized): " << fibSpaceOpt(n) << endl;

    return 0;
}
