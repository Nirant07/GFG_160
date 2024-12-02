/*

Second Largest

Difficulty: Easy

Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.

Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.

Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.

Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

*/

#include <bits/stdc++.h>

using namespace std;

// Driver Code Starts
// User function template for C++

class Solution {
public:
    // Function returns the second largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int largest = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }

        int secondlargest = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != largest) {
                if (arr[i] > secondlargest && largest > arr[i]) {
                    secondlargest = arr[i];
                }
            }
        }

        if (largest == secondlargest || secondlargest == 0) {
            secondlargest = -1;
        }
        return secondlargest;
    }
};

// Driver Code Ends

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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
    }
    cout << "~" << endl;

    return 0;
}