/*
** Number of Islands **

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/


/*
BFS & DFS
** Analysis of Algorithm:
n , m - the dimensions of board
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/
class Solution {
private:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    bool isValid(vector<vector<char>>& grid, int x, int y, vector<vector<bool> >& visited) {
        return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1' && !visited[x][y]);
    }
    
    void BFS(vector<vector<char>>& grid, int x, int y, vector<vector<bool> >& visited) {
        queue<vector<int>> Q;
        Q.push({x, y});
        visited[x][y] = true;
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            for (int i = 0; i < 4; i++) {
                int next_x = cur[0] + directions[i][0];
                int next_y = cur[1] + directions[i][1];
                if (isValid(grid, next_x, next_y, visited)) {
                    Q.push({next_x, next_y});
                    visited[next_x][next_y] = true;
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int cnt = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    cnt++;
                    BFS(grid, i, j, visited);
                }
            }
        }
        return cnt;
    }
};


class Solution {
public:
    void DFS(vector<vector<bool> >& visited, vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || visited[x][y] || grid[x][y] == '0') return;
        visited[x][y] = true;
        DFS(visited, grid, x + 1, y);
        DFS(visited, grid, x - 1, y);
        DFS(visited, grid, x, y + 1);
        DFS(visited, grid, x, y - 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int n = grid.size(), m = grid[0].size(), islands = 0;
        vector<vector<bool> > visited(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    DFS(visited, grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};