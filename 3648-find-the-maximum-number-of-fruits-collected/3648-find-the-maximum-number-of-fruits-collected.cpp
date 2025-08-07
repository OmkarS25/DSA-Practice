class Solution {
public:
    int n, dp[1001][1001];
    int getMax(int i, int j, int dx[3], int dy[3], vector<vector<int>>& fruits) {
        if (i >= n || i < 0 || j >= n || j < 0) return INT_MIN;
        if (i == n - 1 && j == n - 1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int res = INT_MIN;
        for (int k = 0; k < 3; k++) {
            int curr = getMax(i + dx[k], j + dy[k], dx, dy, fruits);
            if (curr != INT_MIN) res = max(res, fruits[i][j] + curr);
        }
        return dp[i][j] = res;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += fruits[i][i];
            fruits[i][i] = 0;
        }
        int dx[3] = {1, 1, 1};
        int dy[3] = {-1, 0, 1};
        memset(dp, -1, sizeof(dp));
        res += getMax(0, n - 1, dx, dy, fruits);
        memset(dp, -1, sizeof(dp));
        res += getMax(n - 1, 0, dy, dx, fruits);
        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();