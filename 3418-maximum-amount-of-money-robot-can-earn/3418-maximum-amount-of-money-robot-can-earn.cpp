static int dp[500][3];

class Solution {
public:
    static int maximumAmount(vector<vector<int>>& coins) {
        const int r=coins.size(), c=coins[0].size();
        // Base case
        int x=coins[0][0];
        dp[0][0]=x;          
        dp[0][1]=dp[0][2]=max(0, x);  

        for(int j=1; j<c; j++){// 0th row
            x=coins[0][j];
            for (int k=2; k>0; k--){
                dp[j][k]=max(x+dp[j-1][k], dp[j-1][k-1]);
            }
            dp[j][0]=x+dp[j-1][0];// k=0
        }

        for (int i=1; i<r; i++) {
            // 0th col
            x=coins[i][0];
            for (int k=2; k>0; k--){
                dp[0][k]=max(x+dp[0][k], dp[0][k-1]);
            }
            dp[0][0]=x+dp[0][0];// k=0
            
            for (int j=1; j<c; j++) {
                x=coins[i][j];
                for (int k=2; k>0; k--) {
                    dp[j][k]=max(max(x+dp[j-1][k], dp[j-1][k-1]), max(x+dp[j][k], dp[j][k-1]));
                }
                dp[j][0]=x+max(dp[j][0], dp[j-1][0]);// k=0

            }
        }
        return dp[c-1][2];
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();