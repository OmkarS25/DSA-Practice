class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 2;
        else if (n == 3) return 5;
        long long MODULO = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 5;
        for (int i = 4; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MODULO; 
        }
        return (int) dp[n];
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();