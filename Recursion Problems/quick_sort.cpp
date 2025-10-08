#include <iostream>
#include <vector>
#include <algorithm> // for swap
using namespace std;

/*
🧩 Problem: Implement Quick Sort using the first element as pivot.

Approach:
1. Choose the first element as the pivot.
2. Use two pointers (i and j):
   - Move i → right until arr[i] > pivot
   - Move j → left until arr[j] <= pivot
3. Swap arr[i] and arr[j] while i < j.
4. Finally, swap pivot (arr[low]) with arr[j].
5. Recursively apply on left and right parts.

Time Complexity:
   - Average: O(n log n)
   - Worst: O(n²)
Space Complexity: O(log n)
*/

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // Move i right until element > pivot
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        // Move j left until element <= pivot
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        // Swap elements if pointers haven't crossed
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Place pivot in correct position
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}

// 🧠 MAIN FUNCTION (For local testing)
int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    cout << "Before Quick Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    arr = quickSort(arr);

    cout << "After Quick Sort:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
