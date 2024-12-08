/*

Stock Buy and Sell – Multiple Transaction Allowed

The cost of stock on each day is given in an array price[]. Each day you may decide to either buy or sell the stock i at price[i], you can even buy and sell the stock on the same day. Find the maximum profit that you can get.

Note: A stock can only be sold if it has been bought previously and multiple stocks cannot be held on any given day.

Examples:

Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210. Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655. Maximum Profit = 210 + 655 = 865.

Input: prices[] = [4, 2, 2, 2, 4]
Output: 2
Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2. Maximum Profit = 2.

Constraints:
1 <= prices.size() <= 105
0 <= prices[i] <= 104

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < prices[i + 1] && buy == 0) {
                buy = prices[i];
            }
            if (prices[i] > prices[i + 1] && buy != 0) {
                sell = prices[i];
                profit += sell - buy;
                buy = 0;
            }
            if (buy != 0 && i == prices.size() - 1) {
                sell = prices[i];
                profit += sell - buy;
            }
        }
        return profit;
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
        int res = ob.maximumProfit(arr);

        cout << res << "\n";
    }

    return 0;
}