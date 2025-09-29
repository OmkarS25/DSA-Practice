class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        // Interval DP problem
        /*
            Let dp[i][j] = minimum triangulation score of the polygon formed by vertices from i to j (inclusive)
            Then dp[i][j] = min over all k in [i + 1..j - 1] {dp[i][k] + dp[k][j] + 
                values[i] * values[k] * values[j] }
        */
        
        int n = values.size();
        vector<vector<int>> dp(n, vector<int> (n, 0)); // n * n matrix initialized to 0

        // go in direction of increasing length to compute smaller required subproblems dp[i][k] & dp[k][j], len = j - i

        for (int len = 2; len <= n - 1; len++) {
            for (int i = 0; i <= n - 1 - len; i++) {
                int j = i + len;
                int best = INT_MAX; // best(minimum) score so far for i..j
                for (int k = i + 1; k <= j - 1; k++) {
                    int score = dp[i][k] + dp[k][j] + (values[i] * values[k] * values[j]);
                    best = min(score, best);
                }
                dp[i][j] = best; // assign min over all k
            }
        }

        return dp[0][n - 1]; // answer for full array
    }
};