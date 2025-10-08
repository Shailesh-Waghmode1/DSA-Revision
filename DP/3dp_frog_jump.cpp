#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

/*
    Problem: Frog Jump
    ------------------
    A frog wants to climb from stair 0 to stair N-1. 
    - At a time, it can jump either 1 or 2 steps.
    - Each stair has a height given in height[N].
    - Energy consumed for a jump from stair i to j is abs(height[i] - height[j]).

    Task: Find the minimum total energy needed to reach the last stair.

    Example:
    Input: height = {30,10,60,10,60,50}
    Output: 40
    Explanation: One optimal path: 0->1->3->5

    Approaches:
    1. Memoization (Top-Down):
       - Recursively compute minimum energy for stair i using previous results.
       - Time Complexity: O(n)
       - Space Complexity: O(n) recursion stack + O(n) dp array

    2. Tabulation (Bottom-Up):
       - Iteratively compute dp[i] = min(dp[i-1]+cost1, dp[i-2]+cost2)
       - Time Complexity: O(n)
       - Space Complexity: O(n)

    3. Space Optimization:
       - Only last two dp values are needed.
       - Time Complexity: O(n)
       - Space Complexity: O(1)
*/

// Memoization (Top-Down)
int frogJumpMemo(int ind, vector<int>& height, vector<int>& dp){
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int jumpOne = frogJumpMemo(ind-1, height, dp) + abs(height[ind]-height[ind-1]);
    int jumpTwo = INT_MAX;
    if(ind > 1) jumpTwo = frogJumpMemo(ind-2, height, dp) + abs(height[ind]-height[ind-2]);

    return dp[ind] = min(jumpOne, jumpTwo);
}

// Tabulation (Bottom-Up)
int frogJumpTab(vector<int>& height){
    int n = height.size();
    vector<int> dp(n, 0);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        int jumpOne = dp[i-1] + abs(height[i]-height[i-1]);
        int jumpTwo = INT_MAX;
        if(i > 1) jumpTwo = dp[i-2] + abs(height[i]-height[i-2]);
        dp[i] = min(jumpOne, jumpTwo);
    }
    return dp[n-1];
}

// Space Optimization
int frogJumpSpaceOpt(vector<int>& height){
    int n = height.size();
    int prev = 0;
    int prev2 = 0;

    for(int i = 1; i < n; i++){
        int jumpOne = prev + abs(height[i]-height[i-1]);
        int jumpTwo = INT_MAX;
        if(i > 1) jumpTwo = prev2 + abs(height[i]-height[i-2]);
        int cur = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main(){
    vector<int> height = {30,10,60,10,60,50};
    int n = height.size();

    vector<int> dp(n, -1);
    cout << "Minimum energy (Memoization): " << frogJumpMemo(n-1, height, dp) << endl;
    cout << "Minimum energy (Tabulation): " << frogJumpTab(height) << endl;
    cout << "Minimum energy (Space Optimized): " << frogJumpSpaceOpt(height) << endl;

    return 0;
}
