class Solution {
public:
    int dfs(int i, int j, int prev, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        const int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int val = grid[i][j];
        if (val <= prev) return 0;
        return dp[i][j] = 1 + max({dfs(i - 1, j + 1, val, grid, dp),
                                   dfs(i, j + 1, val, grid, dp),
                                   dfs(i + 1, j + 1, val, grid, dp)});
    }
    int maxMoves(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dfs(i, 0, -1, grid, dp));
        return ans - 1;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();