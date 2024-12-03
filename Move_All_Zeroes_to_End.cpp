/*

Move All Zeroes to End

Given an array arr[]. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements. Do the mentioned change in the array in place.

Examples:

Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.

Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: No change in array as there are no 0s.

Input: arr[] = [0, 0]
Output: [0, 0]
Explanation: No change in array as there are all 0s.

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105

*/

#include <bits/stdc++.h>

using namespace std;

// User function template for C++
class Solution {

public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();

        vector<int> arr1;

        for(int i=0;i<n;i++){
            if(arr[i] != 0){
                arr1.push_back(arr[i]);
            }
        }

        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr1.push_back(arr[i]);
            }
        }

        for(int i=0;i<n;i++){
            arr[i]=arr1[i];
        }
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
        int n = arr.size();

        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";

    }
    return 0;

}