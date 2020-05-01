/*
** Valid Parenthesis String **

Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

Note:
The string size will be in the range [1, 100].
*/
/*
Genuis idea from https://leetcode.com/problems/valid-parenthesis-string/discuss/107570/JavaC%2B%2BPython-One-Pass-Count-the-Open-Parenthesis

We count the number of ')' we are waiting for,
and it's equal to the number of open parenthesis.
This number will be in a range and we count it as [cmin, cmax]

cmax counts the maximum open parenthesis,
which means the maximum number of unbalanced '(' that COULD be paired.
cmin counts the minimum open parenthesis,
which means the number of unbalanced '(' that MUST be paired.

'*' increase the could match and decrease the must match
')' decrease both

** Analysis of Algorithm:
n - the length of string
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0;
        for (char ch: s) {
            if (ch == '(') {
                cmax++; cmin++;
            }
            if (ch == '*') {// increase could， decrease must
                cmax++; cmin = max(cmin - 1, 0); 
            } 
            if (ch == ')'){
                cmax--; cmin = max(cmin - 1, 0);
            }
            if (cmax < 0) return false;// more ')' than '(' + '*'
        }
        return cmin == 0;
    }
};