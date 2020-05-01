/*
** Maximal Square **

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

/*
Subproblem:
OPT[i][j] = the maximum square length whose bottom right corner is at (i, j) in the matrix

Recurrence
if matrix[i][j] == 0 cannot be in the matrix OPT[i][j] = 0
if matrix[i][j] == 1 can be in the matrix OPT[i][j] = min{OPT[i - 1][j], OPT[i][j - 1], OPT[i - 1][j - 1]} + 1

Base Case
OPT[0][0, m] and OPT[0, n][0] if matrix[i][j] == 1, OPT[i][j] = 1 otherwise OPT[i][j] = 0


Time complexity: O(m * n)
Space complexity: O(m * n) can be optimize to O(m)
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> OPT(n + 1, vector<int>(m + 1, 0));
        int maxLen = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    OPT[i][j] = min(OPT[i - 1][j], min(OPT[i - 1][j - 1], OPT[i][j - 1])) + 1;
                    maxLen = max(maxLen, OPT[i][j]);
                }
            }
        }
        return maxLen * maxLen;
    }
};