#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductPrefixSuffix(vector<int>& nums) {
    int n = nums.size();
    int maxProd = nums[0];
    int prefix = 1, suffix = 1;

    for (int i = 0; i < n; i++) {
        prefix *= nums[i];
        suffix *= nums[n - 1 - i];

        maxProd = max({maxProd, prefix, suffix});

        // Reset if zero
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;
    }

    return maxProd;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = maxProductPrefixSuffix(arr);
    cout << "Maximum product of contiguous subarray: " << result << endl;

    return 0;
}
