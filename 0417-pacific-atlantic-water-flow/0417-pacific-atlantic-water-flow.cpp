class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        const int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        function<void(int, int, vector<vector<bool>>&)> dfs =
            [&](int row, int col, vector<vector<bool>>& visited) {
                visited[row][col] = true;
                for (auto [dx, dy] : dir) {
                    int x = row + dx, y = col + dy;
                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] &&
                        heights[x][y] >= heights[row][col]) {
                        dfs(x, y, visited);
                    }
                }
            };

        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific);
            dfs(i, n - 1, atlantic);
        }

        for (int j = 0; j < n; ++j) {
            dfs(0, j, pacific);
            dfs(m - 1, j, atlantic);
        }
        
        vector<vector<int>> res;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};