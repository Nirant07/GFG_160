/*

Count Inversions

Given an array of integers arr[]. Find the Inversion Count in the array.

Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.

If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int invCount = 0;
        int n = arr.size();

        // Loop through the array
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // If the current element is greater than the next, increment the count
                if (arr[i] > arr[j]) {
                    invCount++;
                }
            }
        }

        return invCount;
    }
};

// Driver Code
int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        int n;
        cin >> n;

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);

        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}