/*
** Minimum Path Sum **

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

/*
Dynamic Programming
Subproblem:
OPT[i][j] = the minimum sum so far from grid[0, i][0, j]
Recurrence:
if i == 0 && j == 0
OPT[i][j] = grid[i][j]

if i > 0 && j == 0
OPT[i][j] = grid[i][j] + OPT[i - 1][j]

if i == 0 && j > 0
OPT[i][j] = grid[i][j] + OPT[i][j - 1]

if i > 0 && j > 0
OPT[i][j] = min(OPT[i - 1][j], OPT[i][j - 1])

** Analysis of Algorithm:
n , m - the dimensions of grid
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        int OPT[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    OPT[i][j] = grid[i][j];
                } else if (i == 0 && j > 0) {
                    OPT[i][j] = grid[i][j] + OPT[i][j - 1];
                } else if (j == 0 && i > 0) {
                    OPT[i][j] = grid[i][j] + OPT[i - 1][j];
                } else {
                    OPT[i][j] = min(OPT[i - 1][j], OPT[i][j - 1]) + grid[i][j];
                }
            }
        }
        return OPT[m - 1][n - 1];
    }
};