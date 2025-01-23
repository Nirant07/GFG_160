/*

Insert Interval

Geek has an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti. He wants to add a new interval newInterval= [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.

Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Examples:

Input: intervals = [[1,3], [4,5], [6,7], [8,10]], newInterval = [5,6]
Output: [[1,3], [4,7], [8,10]]
Explanation: The newInterval [5,6] overlaps with [4,5] and [6,7].

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,9]
Output: [[1,2], [3,10], [12,16]]
Explanation: The new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Constraints:
1 ≤ intervals.size() ≤  105
0 ≤ start[i], end[i] ≤ 109

*/

#include <bits/stdc++.h>

using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        vector<int>& last = res.back();
        vector<int>& curr = intervals[i];

        if (curr[0] <= last[1]) {
            last[1] = max(last[1], curr[1]);
        } else {
            res.push_back(curr);
        }
    }
    return res;
}

// Function to insert a new interval and merge overlaps
vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval);
    return mergeOverlap(intervals);
}

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

        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);

        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << "," << ans[i][1] << "]";
            if (i != ans.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}