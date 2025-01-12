/*

Non Repeating Character

Given a string s consisting of lowercase Latin Letters. Return the first non-repeating character in s. If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.

Examples:

Input: s = "geeksforgeeks"
Output: 'f'
Explanation: In the given string, 'f' is the first character in the string which does not repeat.

Input: s = "racecar"
Output: 'e'
Explanation: In the given string, 'e' is the only character in the string which does not repeat.

Input: s = "aabbccc"
Output: -1
Explanation: All the characters in the given string are repeating.

Constraints:
1 <= s.size() <= 105

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        int n = s.length();

        // Iterate over each character in the string
        for (int i = 0; i < n; ++i) {
            bool found = false;

            // Check if the character repeats in the rest of the string
            for (int j = 0; j < n; ++j) {
                if (i != j && s[i] == s[j]) {
                    found = true;
                    break;
                }
            }

            // If character does not repeat, return it
            if (found == false) {
                return s[i];
            }
        }

        // If no such character is found, return '$'
        return '$';
    }
};

// Driver Code
int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$') {
            cout << ans;
        } else {
            cout << "-1";
        }

        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}