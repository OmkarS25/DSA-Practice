class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxArea = 0;
        
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = (j == 0) ? 1 : dp[i][j - 1] + 1;
                    
                    int width = dp[i][j];
                    
                    for(int k = i; k >= 0; --k) {
                        width = min(width, dp[k][j]);
                        maxArea = max(maxArea, width * (i - k + 1));
                    }
                }
            }
        }
        
        return maxArea;
    }
};


        

