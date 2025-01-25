/*

Non-overlapping Intervals

Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Examples:

Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.

Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
Output: 2
Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.

Input: intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]
Output: 0
Explanation: All ranges are already non overlapping.

Constraints:
1 ≤ intervals.size() ≤  10^5
|intervalsi| == 2
0 ≤ starti < endi <=5*10^4

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minRemoval(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                end = min(intervals[i][1], end);
                cnt++;
            } else {
                end = intervals[i][1];
            }
        }
        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;
        cout << "~" << endl;
    }
    return 0;
}