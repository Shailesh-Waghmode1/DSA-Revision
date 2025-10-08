#include <iostream>
#include <vector>
using namespace std;

/*
🧩 Problem: Combination Sum

Given an array of distinct integers (candidates) and a target,
return all unique combinations where the chosen numbers sum to target.
The same number can be chosen unlimited times.

Example:
Input: [2,3,6,7], target = 7
Output: [[2,2,3], [7]]

Approach:
1. Use recursion + backtracking.
2. At each index, we have two choices:
   - Pick the element (and stay on the same index for reuse)
   - Skip the element (move to next index)
3. Base case:
   - If target == 0 → add the current combination.
   - If index reaches end → stop recursion.
*/

class Solution {
public:
    void findCombination(int ind, int target, vector<int>& arr,
                         vector<vector<int>>& ans, vector<int>& ds) {
        // Base case: reached the end
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // Pick current element if it doesn’t exceed target
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind, target - arr[ind], arr, ans, ds); // stay at same index
            ds.pop_back(); // backtrack
        }

        // Move to next index (don’t pick current element)
        findCombination(ind + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

// 🧠 MAIN FUNCTION (for local testing)
int main() {
    Solution obj;
    vector<int> v = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = obj.combinationSum(v, target);

    cout << "Combinations are:\n";
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
