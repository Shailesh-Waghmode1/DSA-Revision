#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
    Problem: Subsets II (Unique Subsets)
    -------------------------------------
    Given an array of integers that may contain duplicates, return all possible subsets.
    Only unique subsets are allowed. The subsets can be in any order.

    Approach:
    1. Use recursion/backtracking to generate all subsets.
    2. Sort each subset before inserting into a set to avoid duplicates.
    3. Convert the set into a vector<vector<int>> for final answer.

    Time Complexity:
        - O(2^n * n * log n) in worst case
        - 2^n subsets generated, sorting each subset takes O(n log n)
        - Insertion into set takes O(log m) per subset (m = number of unique subsets)

    Space Complexity:
        - O(n) recursion stack
        - O(m * n) for storing unique subsets in set
        - O(m * n) for final answer vector
*/

void printAns(vector<vector<int>> &ans) {
    cout << "The unique subsets are:\n[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "]";
    }
    cout << " ]" << endl;
}

class Solution {
public:
    void fun(vector<int> &nums, int index, vector<int> ds, set<vector<int>> &res) {
        if (index == nums.size()) {
            sort(ds.begin(), ds.end());  // sort before inserting to avoid duplicates
            res.insert(ds);
            return;
        }

        // Pick the element
        ds.push_back(nums[index]);
        fun(nums, index + 1, ds, res);

        // Do not pick the element
        ds.pop_back();
        fun(nums, index + 1, ds, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> ds;
        fun(nums, 0, ds, res);
        for (auto it = res.begin(); it != res.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};

// ------------------------- MAIN FUNCTION -------------------------
int main() {
    Solution obj;

    // Test Case 1
    vector<int> nums1 = {1, 2, 2};
    vector<vector<int>> ans1 = obj.subsetsWithDup(nums1);
    printAns(ans1);

    // Test Case 2
    vector<int> nums2 = {1};
    vector<vector<int>> ans2 = obj.subsetsWithDup(nums2);
    printAns(ans2);

    return 0;
}
