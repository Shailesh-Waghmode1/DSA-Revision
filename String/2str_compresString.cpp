#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Intuition:
-----------
1. Count consecutive repeating characters.
2. Append char + count to the compressed string.
3. Handle the last character group after the loop.
4. Time Complexity: O(n)
*/

string compressString(const string &s) {
    string result = "";
    int count = 1;

    for (int i = 1; i <= s.size(); i++) {
        if (i < s.size() && s[i] == s[i - 1]) {
            count++;
        } else {
            result += s[i - 1];
            result += to_string(count);
            count = 1;
        }
    }
    return result;
}

int main() {
    string s = "aabbbbeeeeffggg";
    cout << compressString(s);
    return 0;
}
