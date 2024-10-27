class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(); 
        vector<int> dp(cols, 0); 
        int totalSquares = 0, topLeft = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int currentTop = dp[j];
                dp[j] = (matrix[i][j] == 1) ? ((j == 0) ? 1 : 1 + min({dp[j], dp[j - 1], topLeft})) : 0; 
                totalSquares += dp[j]; 
                topLeft = currentTop; 
            }
        }
        return totalSquares; 
    }
};


#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();