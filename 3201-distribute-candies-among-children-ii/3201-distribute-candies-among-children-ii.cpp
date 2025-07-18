class Solution {
public:
    long long distributeCandies(int n, int limit) {
        int k = 3;  // Number of people
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int person = 1; person <= k; ++person) {
            vector<long long> newDp(n + 1, 0);
            vector<long long> prefix(n + 2, 0);  // prefix[i] = sum of dp[0..i-1]
            
            for (int i = 0; i <= n; ++i)
                prefix[i + 1] = prefix[i] + dp[i];

            for (int candies = 0; candies <= n; ++candies) {
                int l = max(0, candies - limit);
                int r = candies;
                newDp[candies] = prefix[r + 1] - prefix[l];
            }

            dp = move(newDp);
        }

        return dp[n];
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();