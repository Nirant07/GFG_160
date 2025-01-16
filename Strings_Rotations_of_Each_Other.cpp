/*

Strings Rotations of Each Other

You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Examples :

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.

Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.

Input: s1 = "abcd", s2 = "acbd"
Output: false
Explanation: Strings are not rotations of each other.

Constraints:
1 <= s1.size(), s2.size() <= 10^5

*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool areRotations(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }

        s1 += s1; // Concatenate s1 with itself to create a doubled string

        return s1.find(s2) != string::npos; // Check if s2 exists within the doubled string
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        Solution sol;
        bool result = sol.areRotations(s1, s2);

        if (result) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}