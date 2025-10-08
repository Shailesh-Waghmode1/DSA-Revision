#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
🧩 Problem: Partition Equal Subset Sum (DP-15)

📘 Intuition / Steps:
1. Given an array, check if it can be partitioned into 2 subsets with equal sum.
2. If total sum is odd → impossible.
3. Otherwise, check if a subset exists with sum = totalSum/2 → reduces to Subset Sum problem.
4. Recursive Idea:
   - Base case:
       a) target == 0 → return true
       b) index == 0 → arr[0] == target
   - Otherwise:
       Take or not take the current element recursively.
5. DP Optimization:
   - Memoization → dp[ind][target]
   - Tabulation → fill dp iteratively
   - Space Optimization → 1D array

🕒 Time Complexity:
   - Recursive: O(2^n)
   - Memoization / Tabulation: O(n*k) where k = totalSum/2
   - Space Optimized: O(k)

💾 Space Complexity:
   - Recursive: O(n)
   - Memoization / Tabulation: O(n*k)
   - Space Optimized: O(k)
*/

/* -------------------- 1️⃣ Recursive + Memoization -------------------- */
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;
    if (dp[ind][target] != -1) return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
    bool taken = (arr[ind] <= target) ? subsetSumUtil(ind - 1, target - arr[ind], arr, dp) : false;

    return dp[ind][target] = notTaken || taken;
}

bool canPartition_1memo(int n, vector<int>& arr) {
    int totSum = 0;
    for (int x : arr) totSum += x;
    if (totSum % 2 != 0) return false;

    int k = totSum / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return subsetSumUtil(n - 1, k, arr, dp);
}

/* -------------------- 2️⃣ Tabulation (Bottom-Up) -------------------- */
bool canPartition_2tabu(int n, vector<int>& arr) {
    int totSum = 0;
    for (int x : arr) totSum += x;
    if (totSum % 2 != 0) return false;

    int k = totSum / 2;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= k) dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            bool notTaken = dp[ind - 1][target];
            bool taken = (arr[ind] <= target) ? dp[ind - 1][target - arr[ind]] : false;
            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}

/* -------------------- 3️⃣ Space Optimization -------------------- */
bool canPartition_3spaceOpt(int n, vector<int>& arr) {
    int totSum = 0;
    for (int x : arr) totSum += x;
    if (totSum % 2 != 0) return false;

    int k = totSum / 2;
    vector<bool> prev(k + 1, false);
    prev[0] = true;
    if (arr[0] <= k) prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        vector<bool> cur(k + 1, false);
        cur[0] = true;
        for (int target = 1; target <= k; target++) {
            bool notTaken = prev[target];
            bool taken = (arr[ind] <= target) ? prev[target - arr[ind]] : false;
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }

    return prev[k];
}

/* -------------------- 🧠 Driver Code -------------------- */
int main() {
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    cout << "Recursive + Memoization: " 
         << (canPartition_1memo(n, arr) ? "Yes" : "No") << endl;
    cout << "Tabulation: " 
         << (canPartition_2tabu(n, arr) ? "Yes" : "No") << endl;
    cout << "Space Optimized: " 
         << (canPartition_3spaceOpt(n, arr) ? "Yes" : "No") << endl;

    return 0;
}
