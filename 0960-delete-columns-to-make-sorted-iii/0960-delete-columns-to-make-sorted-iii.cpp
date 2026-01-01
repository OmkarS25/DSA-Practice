class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        
        vector<int> dp(cols, 1);
        int maxLen = 1;
        
        for (int j = 1; j < cols; ++j) {
            for (int i = 0; i < j; ++i) {
                bool canAppend = true;
                for (int r = 0; r < rows; ++r) {
                    if (strs[r][i] > strs[r][j]) {
                        canAppend = false;
                        break;
                    }
                }
                if (canAppend) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            maxLen = max(maxLen, dp[j]);
        }
        
        return cols - maxLen;
    }
};