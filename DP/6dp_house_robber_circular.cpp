#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Problem: House Robber (Circular Street)
    ---------------------------------------
    A thief wants to rob houses arranged in a circle. Each house has some money.
    Robbing two adjacent houses triggers the alarm. Find the maximum money the thief can rob.

    Input: arr = {1, 5, 1, 2, 6}
    Output: 11
    Explanation: Rob houses with 5 and 6 for max sum = 11

    Approaches:
    1. Memoization (Top-Down):
       - Use recursion to decide for each house: pick or skip.
       - Because the street is circular, consider two scenarios:
         a) Exclude the first house
         b) Exclude the last house
       - Time Complexity: O(n)
       - Space Complexity: O(n) for dp + recursion stack

    2. Tabulation (Bottom-Up):
       - Iteratively compute maximum sum for each scenario.
       - Time Complexity: O(n)
       - Space Complexity: O(n)

    3. Space Optimization:
       - Maintain only the last two sums to reduce space.
       - Time Complexity: O(n)
       - Space Complexity: O(1)
*/

// Space Optimized for linear houses
long long houseRobber(vector<int>& arr) {
    int n = arr.size();
    long long prev = arr[0], prev2 = 0;
    for(int i = 1; i < n; i++) {
        long long pick = arr[i] + (i > 1 ? prev2 : 0);
        long long nonPick = prev;
        long long cur = max(pick, nonPick);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

// Main function for circular street
long long robCircularStreet(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return arr[0];

    vector<int> arr1(arr.begin()+1, arr.end()); // exclude first
    vector<int> arr2(arr.begin(), arr.end()-1); // exclude last

    long long ans1 = houseRobber(arr1);
    long long ans2 = houseRobber(arr2);

    return max(ans1, ans2);
}

int main() {
    vector<int> arr = {1, 5, 1, 2, 6};
    cout << "Maximum money robbed: " << robCircularStreet(arr) << endl;
    return 0;
}
