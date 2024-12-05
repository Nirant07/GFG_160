/*

Rotate Array

Given an unsorted array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.

Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.

Constraints:
1 <= arr.size(), d <= 105
0 <= arr[i] <= 105

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        int m = 0;
        for (int i = 0; i < d; i++) {
            m = arr[0];
            for (int j = 0; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[n - 1] = m;
        }
    }
};

int main() {
    int d;
    vector<int> arr, brr, crr;

    string input;
    getline(cin, input);

    stringstream ss(input);
    int number;

    while (ss >> number) {
        arr.push_back(number);
    }

    getline(cin, input);
    ss.clear();
    ss.str(input);

    while (ss >> number) {
        crr.push_back(number);
    }

    d = crr[0];

    int n = arr.size();
    Solution ob;

    // calling rotateArr() function
    ob.rotateArr(arr, d);

    // printing the elements of the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "~" << endl;

    return 0;
}