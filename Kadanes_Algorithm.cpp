/*

Kadane's Algorithm
Difficulty: MediumAccuracy: 36.28%Submissions: 1MPoints: 4
Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray {-2} has the largest sum -2.
Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.
Constraints:
1 ≤ arr.size() ≤ 105
-109 ≤ arr[i] ≤ 104

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int finalsum = INT_MIN; // Initialize to the smallest possible integer

        for (int i = 0; i < n; i++) {
            int sum = 0; // Reset sum for each new starting point

            for (int j = i; j < n; j++) {
                sum += arr[j]; // Add the current element to the sum

                // Update finalsum if the current sum is greater
                if (sum > finalsum) {
                    finalsum = sum;
                }
            }
        }

        return finalsum;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }

    return 0;
}