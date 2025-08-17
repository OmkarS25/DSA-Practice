class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(maxPts, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0, result = 0.0;

        for(int i=1; i <= n; i++){
            double prob = windowSum/maxPts;
            if(i < k) windowSum += prob;
            else result += prob;
            if(i >= maxPts) windowSum -= dp[i % maxPts];
            dp[i % maxPts] = prob;
        }
        return result;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();