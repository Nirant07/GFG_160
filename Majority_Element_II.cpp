/*

Majority Element II

You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

Note: The answer should be returned in an increasing format.

Examples:

Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.

Input: arr[] = [1, 2, 3, 4, 5]
Output: []
Explanation: no candidate occur more than n/3 times.

Constraint:
1 <= arr.size() <= 106
-109 <= arr[i] <= 109

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        vector<int> arr1(2);
        int tot = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1]) {
                int num = 0;
                for (int j = 0; j < arr.size(); j++) {
                    if (arr[i] == arr[j]) {
                        num++;
                    }
                }

                if (num > (arr.size() / 3)) {
                    arr1[tot] = arr[i];
                    if (tot == 0) {
                        tot++;
                    }
                    if (tot == 2) {
                        break;
                    }
                }
            }
        }

        if (tot == 0) {
            return {};
        }

        sort(arr1.begin(), arr1.end());

        if (arr1[0] == arr1[1]) {
            arr1.erase(arr1.begin());
        }

        return arr1;
    }
};

int main() {
    int t;
    cin >> t;

    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        vector<int> nums;

        int num;
        while (ss >> num) {
            nums.push_back(num);
        }

        Solution ob;
        vector<int> ans = ob.findMajority(nums);

        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i: ans) {
                cout << i << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}