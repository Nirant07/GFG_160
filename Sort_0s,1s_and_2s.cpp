/*

Sort 0s, 1s and 2s

Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.

Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.

Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 2

*/

//{ Driver Code Starts.

#include <bits/stdc++.h>

using namespace std;

//} Driver Code Ends
class Solution {

public:
    void sort012(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end()); 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // Added to consume the newline character after the input of 't'

    while (t--) {
        vector<int> a;
        string input;
        int num;

        getline(cin, input); // Read the entire line of input
        stringstream s2(input); // Create a stringstream object to parse the input

        while (s2 >> num) { // Extract numbers from the stringstream
            a.push_back(num);
        }

        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << "~" << endl; // Added for visual separation between test cases
    }
    return 0;
}
// } Driver Code Ends