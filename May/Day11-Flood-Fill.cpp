class Solution {
private:
    vector<int> delta_x = {1, -1, 0, 0};
    vector<int> delta_y = {0, 0, 1, -1};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || image[0].empty()) return image;
        if (image[sr][sc] == newColor) return image;
        int oldColor = image[sr][sc];
        queue<pair<int, int>> Q;
        Q.push({sr, sc});
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int curR = cur.first, curC = cur.second;
            for (int i = 0 ; i < 4; i++) {
                int next_x = curR + delta_x[i];
                int next_y = curC + delta_y[i];
                if (next_x < 0 || next_x >= image.size() || next_y < 0 || next_y >= image[0].size()) continue;
                if (image[next_x][next_y] == oldColor) Q.push({next_x, next_y});
            }
            image[curR][curC] = newColor;
        }
        return image;
    }
};

// BFS
// O(m * n) O(m * n)