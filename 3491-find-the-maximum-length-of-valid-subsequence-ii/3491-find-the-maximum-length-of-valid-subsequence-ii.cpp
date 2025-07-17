class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int answer = 1;               // at least one element works
        vector<int> dp(k);

        // Try every possible common remainder r = 0,1,...,k-1
        for (int r = 0; r < k; ++r) {
            fill(dp.begin(), dp.end(), 0);

            int maxi = 0;

            // Build dp for this fixed r
            for (int x : nums) {
                int p = x % k;
                int partner = (r - p + k) % k;
                dp[p] = max(dp[p], dp[partner] + 1);
                maxi = max(maxi, dp[p]);
            }

            // best subsequence length if common sum % k == r
            answer = max(answer, maxi);
        }

        return answer;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();