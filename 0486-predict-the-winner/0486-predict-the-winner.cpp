// Solution -2 : Bottom-Up DP | Space- Optimized

class Solution {
public:
    bool predictTheWinner(vector<int>& A) {
        int n = A.size();
        if (~n & 1) return true;

        vector<int> dp(n);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = A[i];
            for (int j = i + 1; j < n; j++)
                dp[j] = max(A[i] - dp[j], A[j] - dp[j - 1]);
        }

        return dp[n - 1] >= 0;
    }
};



// Solution - 1 : Recursion | Memoization

// class Solution {
// public:
//     bool predictTheWinner(vector<int>& A) {
//         int n = A.size();
//         if (~n & 1) return true;

//         vector dp(n, vector<int>(n, -1));
//         auto maxDiff = [&](this auto&& maxDiff, int i, int j) -> int {
//             int& res = dp[i][j];
//             if (res != -1) return res;
//             if (i == j) return res = A[i];

//             return res = max(A[i] - maxDiff(i + 1, j),
//                              A[j] - maxDiff(i, j - 1));
//         };

//         return maxDiff(0, n - 1) >= 0;
//     }
// };