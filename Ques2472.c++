/*
2472. Maximum Number of Non-overlapping Palindrome Substrings
Hard
Topics
premium lock icon
Companies
You are given a string s and a positive integer k.

Select a set of non-overlapping substrings from the string s that satisfy the following conditions:

The length of each substring is at least k.
Each substring is a palindrome.
Return the maximum number of substrings in an optimal selection.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abaccdbbd", k = 3
Output: 2
Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.
Example 2:

Input: s = "adbcda", k = 2
Output: 0
Explanation: There is no palindrome substring of length at least 2 in the string.
 

Constraints:

1 <= k <= s.length <= 2000
s consists of lowercase English letters.

*/


class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    //max non-overlapping palindromic pieces (length >= k) from s[i..j]
    int solve(const string& s, int k, int i, int j, vector<vector<int>>& t) {
        int n = s.size();
        if (i >= n || j >= n) 
            return 0;
            
        if (t[i][j] != -1) 
            return t[i][j];

        if (isPalindrome(s, i, j)) {
            int growWindow  = solve(s, k, i, j + 1, t);
            int takeIt      = 1 + solve(s, k, j + 1, j + k, t);
            int slideWindow = solve(s, k, i + 1, j + 1, t);

            return t[i][j] = max({growWindow, takeIt, slideWindow});
        }

        int slideWindow = solve(s, k, i + 1, j + 1, t);
        int growWindow  = solve(s, k, i, j + 1, t);

        return t[i][j] = max(slideWindow, growWindow);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1)
            return n; //each character can be a substring

        vector<vector<int>> t(n, vector<int>(n, -1));

        return solve(s, k, 0, k - 1, t);
    }
};
