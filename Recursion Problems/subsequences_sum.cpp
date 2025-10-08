#include <iostream>
#include <vector>
using namespace std;

/*
🧩 Problem: Print all subsequences of an array whose sum equals targetSum.

Approach:
1. Use recursion to explore all subsequences.
2. Keep track of current index, current sum, and temporary subsequence (ds).
3. Base case → if index == n:
   - If currentSum == targetSum → store that subsequence.
4. Recurse for both choices:
   - Include current element.
   - Exclude current element.

Time Complexity: O(2^n)
Space Complexity: O(n)
*/

class Solution {
public:
    void findSubsequences(int ind, int n, vector<int>& arr, vector<int>& ds,
                          int targetSum, int currentSum, vector<vector<int>>& ans) {
        // Base case
        if (ind == n) {
            if (currentSum == targetSum) {
                ans.push_back(ds);
            }
            return;
        }

        // Include current element
        ds.push_back(arr[ind]);
        findSubsequences(ind + 1, n, arr, ds, targetSum, currentSum + arr[ind], ans);

        // Exclude current element
        ds.pop_back();
        findSubsequences(ind + 1, n, arr, ds, targetSum, currentSum, ans);
    }

    vector<vector<int>> subsequencesWithSum(vector<int>& arr, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = arr.size();
        findSubsequences(0, n, arr, ds, targetSum, 0, ans);
        return ans;
    }
};

// 🧠 MAIN FUNCTION (For local testing)
int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 2, 1};
    int target1 = 2;
    cout << "Test Case 1: arr = {1, 2, 1}, target = 2\n";
    vector<vector<int>> res1 = sol.subsequencesWithSum(arr1, target1);
    for (auto seq : res1) {
        cout << "[ ";
        for (auto x : seq) cout << x << " ";
        cout << "]\n";
    }

    // Test Case 2
    vector<int> arr2 = {1, 2, 3};
    int target2 = 3;
    cout << "\nTest Case 2: arr = {1, 2, 3}, target = 3\n";
    vector<vector<int>> res2 = sol.subsequencesWithSum(arr2, target2);
    for (auto seq : res2) {
        cout << "[ ";
        for (auto x : seq) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
