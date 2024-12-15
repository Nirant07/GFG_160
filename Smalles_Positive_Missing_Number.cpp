/*

Smallest Positive Missing Number

You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.

Examples:

Input: arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.

Input: arr[] = [5, 3, 2, 5, 1]
Output: 4
Explanation: Smallest positive missing number is 4.

Input: arr[] = [-8, 0, -1, -4, -3]
Output: 1
Explanation: Smallest positive missing number is 1.

Constraints:  
1 <= arr.size() <= 105
-106 <= arr[i] <= 106

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        sort(arr.begin(), arr.end()); 

        int res = 1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == res) {
                res++;
            } else if (arr[i] > res) {
                break;
            }
        }

        return res;
    }
};

int main() {
    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }

    return 0;
}