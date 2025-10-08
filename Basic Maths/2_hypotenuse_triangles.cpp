/*
File Name: hypotenuse_triangles.cpp

Problem Statement:
Given N right-angled triangles with coordinates (A,0), (0,B), and (0,0),
find the length of the hypotenuse of each triangle. If the length is 
decimal, round it up to the next greater integer.

Input:
First line: N (number of triangles)
Next N lines: two integers A and B for each triangle

Output:
N lines, each representing the length of the hypotenuse of the corresponding triangle

Example:
Input:
2
20 21
8 15
Output:
29
*/

#include <iostream>
#include <cmath>    // for sqrt() and ceil()
using namespace std;

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        long long A, B;
        cin >> A >> B;

        double hypotenuse = sqrt(1.0*A*A + 1.0*B*B);
        cout << (long long)ceil(hypotenuse) << endl;
    }

    return 0;
}
