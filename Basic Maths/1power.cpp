/*
Problem Statement:
Given two integers A and B representing the sides of a larger cube and a smaller cube respectively,
find how many smaller cubes of side B can fit inside the larger cube of side A.

Formula:
Number of smaller cubes = (A³) / (B³)

Example:
Input: 4 2
Output: 8
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long A, B;
    cin >> A >> B;

    // Calculate volume of larger and smaller cubes
    long long largerVolume = pow(A, 3);
    long long smallerVolume = pow(B, 3);

    // Print number of smaller cubes
    cout << largerVolume / smallerVolume;

    return 0;
}
