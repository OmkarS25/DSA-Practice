auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        const int m = points.size();
        const int n = points[0].size();
        vector<long long> dp(n, 0);
        long long ans = 0;

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                dp[j] += points[i][j];
                ans = max(ans, dp[j]);
            }

            long long maxV = 0;

            for (int j = 0;j < n;j++) {
                maxV = dp[j] = max(maxV-1, dp[j]);
            }

            maxV = 0;
            for (int j = n-1;j >= 0;j--) {
                maxV = dp[j] = max(maxV-1, dp[j]);
            }
        }

        return ans;
    }
};



// class Solution {
// public:
//     long long maxPoints(vector<vector<int>>& points) {
//         int row = points.size(), col = points[0].size();
//         vector<long long> dp(col, 0);
        
//         for(int i = 0; i < col; i++) {
//             dp[i] = points[0][i];
//         }
        
//         for(int r = 1; r < row; r++) {
//             vector<long long> leftMax(col, 0), rightMax(col, 0);
//             vector<long long> newDp(col, 0);
            
//             leftMax[0] = dp[0];
//             for(int i = 1; i < col; i++) {
//                 leftMax[i] = max(leftMax[i-1], dp[i] + i);
//             }
            
//             rightMax[col-1] = dp[col-1] - (col-1);
//             for(int i = col-2; i >= 0; i--) {
//                 rightMax[i] = max(rightMax[i+1], dp[i] - i);
//             }
            
//             for(int i = 0; i < col; i++) {
//                 newDp[i] = max(leftMax[i] - i, rightMax[i] + i) + points[r][i];
//             }
            
//             dp = newDp;
//         }

//         return *max_element(dp.begin(), dp.end());
//     }
// };