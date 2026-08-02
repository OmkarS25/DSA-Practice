// Solution -2 : Bottom-Up DP | Space- Optimized

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        if (~n & 1) return true;

        vector<int> dp(n);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = piles[i];
            for (int j = i + 1; j < n; j++)
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
        }

        return dp[n - 1] >= 0;
    }
};



// Solution - 1 : Recursion | Memoization

// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         int n = piles.size();
//         if (~n & 1) return true;

//         vector dp(n, vector<int>(n, -1));
//         auto maxDiff = [&](this auto&& maxDiff, int i, int j) -> int {
//             int& res = dp[i][j];
//             if (res != -1) return res;
//             if (i == j) return res = piles[i];

//             return res = max(piles[i] - maxDiff(i + 1, j),
//                              piles[j] - maxDiff(i, j - 1));
//         };

//         return maxDiff(0, n - 1) >= 0;
//     }
// };