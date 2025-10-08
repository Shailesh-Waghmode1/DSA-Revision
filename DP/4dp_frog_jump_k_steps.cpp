#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

/*
    Problem: Frog Jump with K Steps
    --------------------------------
    A frog wants to climb from stair 0 to stair N-1. 
    - At a time, it can jump 1 to K steps.
    - Each stair has a height given in height[N].
    - Energy consumed for a jump from stair i to j is abs(height[i] - height[j]).

    Task: Find the minimum total energy to reach the last stair.

    Example:
    Input: height = {30, 10, 60, 10, 60, 50}, K = 2
    Output: 40
    Explanation: Optimal path considering jumps up to K steps.

    Approaches:
    1. Memoization (Top-Down):
       - Recursively compute min energy using all possible jumps up to K.
       - Time Complexity: O(n*K)
       - Space Complexity: O(n) recursion stack + O(n) dp array

    2. Tabulation (Bottom-Up):
       - Iteratively compute dp[i] = min(dp[i-j] + cost) for j = 1..K
       - Time Complexity: O(n*K)
       - Space Complexity: O(n)

    3. Space Optimization:
       - Cannot fully optimize to O(1) because we may need last K dp values.
       - But can maintain a sliding window of K elements if needed.
       - Time Complexity: O(n*K)
       - Space Complexity: O(n)
*/

// Memoization (Top-Down)
int frogJumpKMemo(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int mmSteps = INT_MAX;
    for(int j = 1; j <= k; j++){
        if(ind - j >= 0){
            int jump = frogJumpKMemo(ind-j, height, dp, k) + abs(height[ind]-height[ind-j]);
            mmSteps = min(mmSteps, jump);
        }
    }
    return dp[ind] = mmSteps;
}

// Tabulation (Bottom-Up)
int frogJumpKTab(vector<int>& height, int k){
    int n = height.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i-j >= 0){
                dp[i] = min(dp[i], dp[i-j] + abs(height[i]-height[i-j]));
            }
        }
    }
    return dp[n-1];
}

// Space Optimization (Sliding Window, optional)
int frogJumpKSpaceOpt(vector<int>& height, int k){
    int n = height.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i-j >= 0){
                dp[i] = min(dp[i], dp[i-j] + abs(height[i]-height[i-j]));
            }
        }
    }
    return dp[n-1];
}

int main(){
    vector<int> height = {30, 10, 60, 10, 60, 50};
    int k = 2;
    int n = height.size();

    vector<int> dp(n, -1);
    cout << "Minimum energy (Memoization): " << frogJumpKMemo(n-1, height, dp, k) << endl;
    cout << "Minimum energy (Tabulation): " << frogJumpKTab(height, k) << endl;
    cout << "Minimum energy (Space Optimized): " << frogJumpKSpaceOpt(height, k) << endl;

    return 0;
}
