class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int res = 0;

        // Step 1: Precompute the number of consecutive ones to the left of each cell
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    dp[i][j] = (j == 0 ? 1 : dp[i][j - 1] + 1);
                }
            }
        }

        // Step 2: For each cell, look upwards and find the minimum width of 1s
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                int minWidth = dp[i][j];
                for (int k = i; k >= 0 && dp[k][j] > 0; --k) {
                    minWidth = min(minWidth, dp[k][j]);
                    res += minWidth;
                }
            }
        }

        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();