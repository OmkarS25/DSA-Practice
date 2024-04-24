class Solution {
public:
    int sum(int n, vector<int>&dp){
        if(0==n) return 0;
        if(1==n || 2==n) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = sum(n-1, dp) + sum(n-2, dp) + sum(n-3, dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return sum(n, dp);
    }
};