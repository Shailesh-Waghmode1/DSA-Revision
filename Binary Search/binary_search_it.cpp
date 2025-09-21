/*
----------------------------------------------------
🔹 Binary Search (Iterative Approach) Algorithm
----------------------------------------------------
1. Start with two pointers: low = 0, high = n-1.
2. While low <= high:
   a. Find mid = low + (high - low) / 2.
   b. If arr[mid] == target → return mid (found).
   c. If arr[mid] < target → search in right half → low = mid + 1.
   d. Else → search in left half → high = mid - 1.
3. If not found, return -1.

🔸 Time Complexity: O(log n)
🔸 Space Complexity: O(1)
----------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// Function for iterative binary search
int binarySearchIterative(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // avoid overflow

        if (arr[mid] == target)
            return mid; // target found
        else if (arr[mid] < target)
            low = mid + 1; // search right half
        else
            high = mid - 1; // search left half
    }
    return -1; // target not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int result = binarySearchIterative(arr, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
