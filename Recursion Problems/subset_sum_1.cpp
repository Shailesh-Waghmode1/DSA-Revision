#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Problem: Subset Sums
    -----------------------
    Given an array of integers, find the sum of all subsets.
    Each subset sum is included once, and the output is sorted.

    Approach:
    1. Use recursion/backtracking.
    2. At each index, choose either:
       - Include the current element in sum.
       - Exclude the current element from sum.
    3. Base case: if index == n, push the current sum into ans.

    Time Complexity:
        - O(2^n) for generating all subsets
        - Sorting adds O(2^n * log(2^n)) for final sort

    Space Complexity:
        - O(n) recursion stack
        - O(2^n) for storing all subset sums
*/

class Solution {
public:
    void subsetSumsHelper(int ind, vector<int> &arr, int n, vector<int> &ans, int sum) {
        if (ind == n) {
            ans.push_back(sum);
            return;
        }

        // Pick the element
        subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);

        // Do not pick the element
        subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }

    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        subsetSumsHelper(0, arr, n, ans, 0);
        sort(ans.begin(), ans.end());  // sort for ascending order
        return ans;
    }
};

// ------------------------- MAIN FUNCTION -------------------------
int main() {
    vector<int> arr = {3, 1, 2};
    Solution ob;

    vector<int> ans = ob.subsetSums(arr, arr.size());

    cout << "The sum of each subset is:\n";
    for (int sum : ans) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
