#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Problem: Combination Sum II
    ---------------------------------
    Given a collection of candidate numbers (may contain duplicates)
    and a target number, find all unique combinations in candidates
    where the numbers sum to the target.

    Each number may be used only once.

    Approach:
    1. Sort the array to easily skip duplicates.
    2. Use backtracking to explore all combinations.
    3. Skip duplicate elements in the same recursive level.
    4. Stop recursion if current element > remaining target.

    Time Complexity:
        - Worst case: O(2^n * k), where:
            n = number of candidates
            k = average length of a valid combination (for copying to answer)
        - Explanation: In the worst case, each element can be either picked or not picked,
          generating up to 2^n subsets. Copying each valid combination into the result takes O(k).

    Space Complexity:
        - O(k) for recursion stack + O(m*k) for storing answer
        - k = maximum depth of recursion (length of combination)
        - m = number of valid combinations stored in ans

    Test Cases:
    --------------------------
    Test Case 1:
        Input: candidates = [10,1,2,7,6,1,5], target = 8
        Output: [[1,1,6],[1,2,5],[1,7],[2,6]]

    Test Case 2:
        Input: candidates = [2,5,2,1,2], target = 5
        Output: [[1,2,2],[5]]

    Test Case 3:
        Input: candidates = [3,1,3,5,1,1], target = 8
        Output: [[1,1,1,5],[1,3,4],[3,5]]
*/

void findCombination(int ind, int n, int target, vector<int> &arr,
                     vector<vector<int>> &ans, vector<int> &ds) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < n; i++) {
        // Skip duplicates
        if (i > ind && arr[i] == arr[i - 1]) continue;

        // Stop early if element exceeds target
        if (arr[i] > target) break;

        // Include current element
        ds.push_back(arr[i]);
        findCombination(i + 1, n, target - arr[i], arr, ans, ds); // move to next index
        ds.pop_back(); // backtrack
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    int n = candidates.size();
    sort(candidates.begin(), candidates.end()); // sort for duplicates
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, n, target, candidates, ans, ds);
    return ans;
}

// ------------------------- MAIN FUNCTION -------------------------
int main() {
    vector<int> v = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> comb = combinationSum2(v, target);

    cout << "Combinations are:\n[ ";
    for (const auto &subset : comb) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << " ]" << endl;

    return 0;
}
