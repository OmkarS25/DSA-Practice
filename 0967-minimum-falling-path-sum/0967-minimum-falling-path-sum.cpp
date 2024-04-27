class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n , vector<int>(n));
        for(int i=0 ; i<n ; i++) {
            dp[0][i] = matrix[0][i];
        }
        for(int i=1 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                int leftUp = INT_MAX;
                int rightUp = INT_MAX;
                int prevSum = dp[i-1][j];
                if((j-1) >= 0) 
                    leftUp = dp[i-1][j-1];
                if((j+1) < n)
                    rightUp = dp[i-1][j+1];
                
                dp[i][j] = matrix[i][j] + min(prevSum , min(rightUp, leftUp));
            }
        }
        int ans = INT_MAX;
        for(int i=0 ; i<n ; i++) {
            if(dp[n-1][i] < ans) {
                ans = dp[n-1][i];
            }
        }
        return ans;
    }
};