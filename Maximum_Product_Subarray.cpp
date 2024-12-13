/*

Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the output fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.

Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.

Input: arr[] = [2, 3, 4] 
Output: 24 
Explanation: For an array with all positive elements, the result is product of all elements. 

Constraints:
1 ≤ arr.size() ≤ 106
-10  ≤  arr[i]  ≤  10

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int curr_max = arr[0];
        int curr_min = arr[0];
        int overall_max = arr[0];

        for (int i = 1; i < n; i++) {
            int temp = max({arr[i], curr_max * arr[i], curr_min * arr[i]});
            curr_min = min({arr[i], curr_max * arr[i], curr_min * arr[i]});
            curr_max = temp;
            overall_max = max(overall_max, curr_max);
        }

        return overall_max;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxProduct(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}