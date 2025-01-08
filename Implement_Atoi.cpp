/*

Implement Atoi

Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

Cases for atoi() conversion:

Skip any leading whitespaces.
Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.

Examples:

Input: s = "-123"
Output: -123
Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer

Input: s = "  -"
Output: 0
Explanation: No digits are present, therefore the returned answer is 0.

Input: s = " 1231231231311133"
Output: 2147483647
Explanation: The converted number will be greater than 231 – 1, therefore print 231 – 1 = 2147483647.

Input: s = "-999999999999"
Output: -2147483648
Explanation: The converted number is smaller than -231, therefore print -231 = -2147483648.
Input: s = "  -0012gfg4"
Output: -12
Explanation: Nothing is read after -12 as a non-digit character ‘g’ was encountered.

Constraints:
1 ≤ |s| ≤ 15

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(char *s) {
        int sign = 1, res = 0, idx = 0;

        // Ignore leading whitespaces
        while (s[idx] == ' ') {
            idx++;
        }

        // Store the sign of number
        if (s[idx] == '-' || s[idx] == '+') {
            sign = (s[idx++] == '-') ? -1 : 1;
        }

        // Construct the number digit by digit
        while (s[idx] >= '0' && s[idx] <= '9') {
            // handling overflow/underflow test case
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && s[idx] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            // Append current digit to the result
            res = 10 * res + (s[idx++] - '0');
        }
        return res * sign;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}