class Solution {
public:
    array<int, 4> di = {1, -1, 0, 0}, dj = {0, 0, 1, -1};
    int largestIsland(vector<vector<int>>& grid) {
        int color = 2, n = grid.size();
        unordered_map<int, int> land_size;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int comp_size = color_component(grid, {i, j}, color);
                    land_size[color] = comp_size;
                    color++;
                }
            }
        }
        int result = 0;
        for (auto [_, land_val] : land_size) {
            result = max(result, land_val);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    continue;
                unordered_map<int, bool> united_colors;
                for (int k = 0; k < 4; k++) {
                    int ii = i + di[k], jj = j + dj[k];
                    if (!is_valid(ii, jj, n) || grid[ii][jj] == 0) continue;
                    united_colors[grid[ii][jj]] = 1;
                }
                
                int united_size = 0, count = 0;
                for (auto [key, _] : united_colors) {
                    united_size += land_size[key];
                    count++;
                }
                united_size++; // the water cell transformed
                result = max(result, united_size);
            }
        }
        return result;
    }
    int color_component(vector<vector<int>>& g, vector<int> start, int color) {
        int result = 0, n = g.size();
        g[start[0]][start[1]] = color;
        queue<vector<int>>q;
        q.push(start);
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            result++;
            for (int i = 0; i < 4; i++) {
                int ii = f[0] + di[i], jj = f[1] + dj[i];
                if (!is_valid(ii, jj, n))
                    continue;
                if (g[ii][jj] == 1) {
                    q.push({ii, jj});
                    g[ii][jj] = color;
                }
            }
        }
        return result;
    }
    bool is_valid(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();