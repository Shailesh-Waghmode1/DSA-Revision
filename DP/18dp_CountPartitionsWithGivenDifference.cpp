// File: 18dp_CountPartitionsWithGivenDifference.cpp

#include <iostream>
#include <vector>
using namespace std;

/*
🧩 Problem: Count Partitions with Given Difference (DP-18)

📘 Intuition / Steps:
1. Given an array, partition it into two subsets such that their sum difference = D.
2. Let sum(S1) - sum(S2) = D and sum(S1) + sum(S2) = totalSum
   → sum(S1) = (D + totalSum) / 2
3. Reduce to counting subsets with sum = (totalSum - D)/2
4. Recursive + DP approach:
   - Base case handles zero elements specially (0 can be included or excluded)
   - Use memoization for storing intermediate results
5. DP Optimization:
   - Tabulation → 2D dp[ind][target]
   - Space Optimization → 1D array

🕒 Time Complexity:
   - Memoization / Tabulation: O(N*K), K = (totalSum-D)/2
   - Space Optimized: O(K)

💾 Space Complexity:
   - Memoization / Tabulation: O(N*K)
   - Space Optimized: O(K)
*/

const int MOD = 1e9 + 7;

/* -------------------- 1️⃣ Recursive + Memoization -------------------- */
int countSubsetsUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2; // pick or not pick
        if (target == 0 || target == arr[0]) return 1;
        return 0;
    }
    if (dp[ind][target] != -1) return dp[ind][target];

    int notTaken = countSubsetsUtil(ind - 1, target, arr, dp);
    int taken = (arr[ind] <= target) ? countSubsetsUtil(ind - 1, target - arr[ind], arr, dp) : 0;

    return dp[ind][target] = (notTaken + taken) % MOD;
}

int countSubsets_1memo(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return countSubsetsUtil(n - 1, target, arr, dp);
}

/* -------------------- 2️⃣ Tabulation (Bottom-Up) -------------------- */
int countSubsets_2tabu(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    if (arr[0] == 0) dp[0][0] = 2; 
    else dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        for (int t = 0; t <= target; t++) {
            int notTaken = dp[ind - 1][t];
            int taken = (arr[ind] <= t) ? dp[ind - 1][t - arr[ind]] : 0;
            dp[ind][t] = (notTaken + taken) % MOD;
        }
    }
    return dp[n - 1][target];
}

/* -------------------- 3️⃣ Space Optimization -------------------- */
int countSubsets_3spaceOpt(vector<int>& arr, int target) {
    int n = arr.size();
    vector<int> prev(target + 1, 0);

    if (arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if (arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        vector<int> cur(target + 1, 0);
        for (int t = 0; t <= target; t++) {
            int notTaken = prev[t];
            int taken = (arr[ind] <= t) ? prev[t - arr[ind]] : 0;
            cur[t] = (notTaken + taken) % MOD;
        }
        prev = cur;
    }
    return prev[target];
}

/* -------------------- Count Partitions with Difference D -------------------- */
int countPartitions(int n, int D, vector<int>& arr) {
    int totalSum = 0;
    for (int x : arr) totalSum += x;

    // Check for invalid cases
    if (totalSum - D < 0 || (totalSum - D) % 2 != 0) return 0;

    int target = (totalSum - D) / 2;

    return countSubsets_3spaceOpt(arr, target);
}

/* -------------------- 🧠 Driver Code -------------------- */
int main() {
    vector<int> arr = {5, 2, 6, 4};
    int D = 3;
    int n = arr.size();

    cout << "The number of partitions with difference " << D 
         << " is: " << countPartitions(n, D, arr) << endl;

    return 0;
}
