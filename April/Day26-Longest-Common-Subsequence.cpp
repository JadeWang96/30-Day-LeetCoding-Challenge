/*
** Longest Common Subsequence **

Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.

 
Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
*/

/*
Dynamic Programming
Subproblem:
OPT[i][j] = the longest common subsequence of text1[0 ... i] & text2[0 ... j].
here reverse from the tail to head -> easy to boundary condition

Recurrence
if text1[i] == text2[j] OPT[i][j] = 1 + OPT[i - 1][j - 1]
otherwise OPT[i][j] = max(OPT[i - 1][j], OPT[i][j - 1])

Base Case
Boundary conditions

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size(), size2 = text2.size();
        if (size1 == 0 || size2 == 0) return 0;
        vector<vector<int>> OPT(size1 + 1, vector<int>(size2 + 1, 0));
        for (int row = size1 - 1; row >= 0; row--) {
            for (int col = size2 - 1; col >= 0; col--) {
                if (text1[row] == text2[col]) {
                    OPT[row][col] = 1 + OPT[row + 1][col + 1];
                } else {
                    OPT[row][col] = max(OPT[row + 1][col], OPT[row][col + 1]);
                }
            }
        }

        return OPT[0][0];
    }
};