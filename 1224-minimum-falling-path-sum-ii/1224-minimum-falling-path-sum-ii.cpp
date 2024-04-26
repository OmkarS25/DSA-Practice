class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), res = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j = 0; j < n; ++j) 
            dp[0][j] = grid[0][j];
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int temp = INT_MAX;
                for(int k = 0; k < n; ++k) {
                    if(k != j) 
                        temp = min(temp, grid[i][j] + dp[i - 1][k]);
                    dp[i][j] = temp;
                }
            }
        }
        for(int j = 0; j < n; ++j)
            res = min(res, dp[n - 1][j]);
        return res;
    }
};

// MY SOlUTION, BUT HAZ SOME PROBLEM.
// class Solution {
// public:
//     int solve(vector<vector<int>> grid, int i, int j, vector<vector<int>> &dp, int avoid){
//         if (i == grid.size()) return 0; // We've reached beyond the last row
//         if (j < 0 || j >= grid[0].size()) return INT_MAX; 
//         if(dp[i][j] != 100) return dp[i][j];
//         int minsum = INT_MAX;
//         for (int col = 0; col < grid[0].size(); ++col) {
//             if (col != avoid) {
//                 minsum = min(minsum, solve(grid, i + 1, col, dp, j));
//             }
//         }
//         dp[i][j] = grid[i][j] + minsum;
//         return dp[i][j];
//     }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 100));
//         int minsum = INT_MAX;
//         for(int i=0; i<grid[0].size(); i++){
//             minsum = min(minsum, solve(grid, 0, i, dp, -1));
//         }
//         return minsum;
//     }
// };