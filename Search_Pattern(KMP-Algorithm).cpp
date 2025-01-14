/*

Search Pattern (KMP-Algorithm)

Given two strings, one is a text string txt and the other is a pattern string pat. The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
Note: Return an empty list in case of no occurrences of pattern.

Examples :

Input: txt = "abcab", pat = "ab"
Output: [0, 3]
Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 

Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.

Input: txt = "aabaacaadaabaaba", pat = "aaba"
Output: [0, 9, 12]


Constraints:
1 ≤ txt.size() ≤ 106
1 ≤ pat.size() < txt.size()
Both the strings consist of lowercase English alphabets.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void constructLps(string &pat, vector<int> &lps) {
        // len stores the length of longest prefix which
        // is also a suffix for the previous index
        int len = 0;

        // lps[0] is always 0
        lps[0] = 0;

        int i = 1;
        while (i < pat.length()) {
            // If characters match, increment the size of lps
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            // If there is a mismatch
            else {
                if (len != 0) {
                    // Update len to the previous lps value
                    // to avoid redundant comparisons
                    len = lps[len - 1];
                } else {
                    // If no matching prefix found, set lps[i] to 0
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string &pat, string &txt) {
        int n = txt.length();
        int m = pat.length();

        vector<int> lps(m);
        vector<int> res;

        constructLps(pat, lps);

        // Pointers i and j, for traversing
        // the text and pattern
        int i = 0;
        int j = 0;

        while (i < n) {
            // If characters match, move both pointers forward
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            // If the entire pattern is matched
            // store the start index in result
            if (j == m) {
                res.push_back(i - j);

                // Use LPS of previous index to
                // skip unnecessary comparisons
                j = lps[j - 1];
            }
            // If there is a mismatch
            else if (i < n && pat[j] != txt[i]) {
                // Use lps value of previous index
                // to avoid redundant comparisons
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);

        if (res.size() == 0) {
            cout << "[]";
        } else {
            for (int i : res) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends