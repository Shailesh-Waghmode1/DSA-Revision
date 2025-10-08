#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for max()

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        int maxLen = 0;
        int left = 0;
        vector<int> LastIdx(256, -1); // last index of each ASCII char

        for (int right = 0; right < s.size(); right++) {
            if (LastIdx[s[right]] >= left) {
                left = LastIdx[s[right]] + 1; // move left past duplicate
            }

            LastIdx[s[right]] = right; // update last index
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
