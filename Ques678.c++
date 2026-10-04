/*

678. Valid Parenthesis String
Medium
Topics
premium lock icon
Companies
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true
Example 4:

Input: s = "("
Output: false
 

Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

*/

class Solution {

    Boolean[][] memo;

    public boolean checkValidString(String s) {

        // index = current position
        // balance can be at most s.length()
        memo = new Boolean[s.length()][s.length() + 1];

        return solve(s, 0, 0);
    }

    private boolean solve(String s, int index, int balance) {

        // Invalid path
        if (balance < 0) {
            return false;
        }

        // All characters are processed
        if (index == s.length()) {
            return balance == 0;
        }

        // Already calculated
        if (memo[index][balance] != null) {
            return memo[index][balance];
        }

        char currentCharacter = s.charAt(index);

        boolean result;

        // '('
        if (currentCharacter == '(') {

            result = solve(s, index + 1, balance + 1);
        }

        // ')'
        else if (currentCharacter == ')') {

            result = solve(s, index + 1, balance - 1);
        }

        // '*'
        else {

            // '*' as '('
            boolean useAsOpening =
                solve(s, index + 1, balance + 1);

            // '*' as ')'
            boolean useAsClosing =
                solve(s, index + 1, balance - 1);

            // '*' as empty
            boolean useAsEmpty =
                solve(s, index + 1, balance);

            result = useAsOpening ||
                     useAsClosing ||
                     useAsEmpty;
        }

        // Store answer for this state
        memo[index][balance] = result;

        return result;
    }
}
