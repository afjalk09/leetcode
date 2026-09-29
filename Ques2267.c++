/*


Avatar
afjalk09
Access all features with our Premium subscription!
myLists
My Lists
notebook
Notebook
progress
Progress
points
Points
Problems
Discuss
Contest
Interview
Store
Try New Features
Orders
My Playgrounds
Settings
Appearance
Sign Out
2267. Check if There Is a Valid Parentheses String Path
Hard
Topics
premium lock icon
Companies
A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:

The path starts from the upper left cell (0, 0).
The path ends at the bottom-right cell (m - 1, n - 1).
The path only ever moves down or right.
The resulting parentheses string formed by the path is valid.
Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

 

Example 1:


Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.
Example 2:


Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is either '(' or ')'.

*/
//Approach-1 (Recursion Memo)
//T.C : O(m*n*(m+n))
//S.C : O(m*n*(m+n))
class Solution {
public:
    int m, n;
    int t[101][101][201];

    bool solve(int i, int j, int openCount, vector<vector<char>>& grid) {
        openCount += (grid[i][j] == '(') ? 1 : -1;

        if(openCount < 0)
            return false;

        if(t[i][j][openCount] != -1) {
            return t[i][j][openCount];
        }
        
        if(i == m-1 && j == n-1)
            return t[i][j][openCount] = (openCount == 0);

        //mode down
        if(i+1 < m) {
            if(solve(i+1, j, openCount, grid)) 
                return t[i][j][openCount] = true;
        }

        //mode right
        if(j+1 < n) {
            if(solve(i, j+1, openCount, grid)) 
                return t[i][j][openCount] = true;
        }

        return t[i][j][openCount] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if((m+n-1) % 2 == 1) 
            return false;
        
        if(grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;
        
        memset(t, -1, sizeof(t));

        return solve(0, 0, 0, grid);

    }
};


