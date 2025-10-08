#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to rotate array right by k positions
void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) return;

    k = k % n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;

    rotateArray(arr, k);

    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
