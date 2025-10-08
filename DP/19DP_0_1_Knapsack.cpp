// File: 19DP_0_1_Knapsack.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
🧩 Problem: 0/1 Knapsack (DP-19)

📘 Problem Statement:
A thief wants to rob a store carrying a bag of capacity W. There are n items with 
weights 'wt' and values 'val'. The thief can include or exclude items but cannot 
take a fraction. Find the maximum value he can steal.

📘 Intuition / Steps:
1. Recursive approach:
   - Base case: if ind==0 or W==0, return 0
   - Recursion: include current item (if weight allows) or exclude it

2. Memoization:
   - Store intermediate results in dp[ind][W] to avoid recomputation

3. Tabulation:
   - Iteratively fill dp table bottom-up

4. Space Optimization:
   - Only keep previous row (or one-dimensional dp) since dp[ind][W] depends only on dp[ind-1][..]

🕒 Time Complexity:
- Recursive: O(2^N)
- Memoization / Tabulation: O(N*W)
- Space Optimized: O(W)

💾 Space Complexity:
- Recursive: O(N) recursion stack
- Memoization / Tabulation: O(N*W)
- Space Optimized: O(W)
*/

/* -------------------- 1️⃣ Recursive + Memoization -------------------- */
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (wt[0] <= W) return val[0];
        return 0;
    }

    if (dp[ind][W] != -1) return dp[ind][W];

    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);
    int taken = INT_MIN;
    if (wt[ind] <= W) taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp);

    return dp[ind][W] = max(notTaken, taken);
}

int knapsack_1memo(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapsackUtil(wt, val, n - 1, W, dp);
}

/* -------------------- 2️⃣ Tabulation (Bottom-Up DP) -------------------- */
int knapsack_2tabu(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base case: fill first row
    for (int w = wt[0]; w <= W; w++) dp[0][w] = val[0];

    for (int ind = 1; ind < n; ind++) {
        for (int w = 0; w <= W; w++) {
            int notTaken = dp[ind - 1][w];
            int taken = INT_MIN;
            if (wt[ind] <= w) taken = val[ind] + dp[ind - 1][w - wt[ind]];
            dp[ind][w] = max(notTaken, taken);
        }
    }

    return dp[n - 1][W];
}

/* -------------------- 3️⃣ Space Optimization -------------------- */
int knapsack_3spaceOpt(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<int> prev(W + 1, 0);

    for (int w = wt[0]; w <= W; w++) prev[w] = val[0];

    for (int ind = 1; ind < n; ind++) {
        for (int w = W; w >= 0; w--) { // traverse backwards to avoid overwriting
            int notTaken = prev[w];
            int taken = INT_MIN;
            if (wt[ind] <= w) taken = val[ind] + prev[w - wt[ind]];
            prev[w] = max(notTaken, taken);
        }
    }

    return prev[W];
}

/* -------------------- 🧠 Driver Code -------------------- */
int main() {
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5;
    int n = wt.size();

    cout << "Recursive + Memoization: " << knapsack_1memo(wt, val, n, W) << endl;
    cout << "Tabulation: " << knapsack_2tabu(wt, val, n, W) << endl;
    cout << "Space Optimized: " << knapsack_3spaceOpt(wt, val, n, W) << endl;

    return 0;
}
