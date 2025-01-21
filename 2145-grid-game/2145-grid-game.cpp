#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n =grid[0].size();
        long long a = 0, b = 0;
        for(int i=0; i<n; i++){
            a += grid[0][i];
            b += grid[1][i];
        }
        long long ans = LLONG_MAX, a1 = 0, b1 = 0;
        for(int i=0; i<n; i++){
            a1 += grid[0][i];
            long long s1 = a-a1, s2 = b1;
            s1 = max(s1,s2);
            ans = min(ans,s1);
            b1 += grid[1][i];
        }
        return ans;
    }
};

// class Solution {
// public:
//     long long gridGame(vector<vector<int>>& grid) {
//         int n = grid[0].size();
//         vector<long long> topPrefix(n + 1, 0), bottomPrefix(n + 1, 0);
//         for (int i = 0; i < n; ++i) {
//             topPrefix[i + 1] = topPrefix[i] + grid[0][i];
//             bottomPrefix[i + 1] = bottomPrefix[i] + grid[1][i];
//         }
//         long long result = LLONG_MAX;
//         for (int i = 0; i < n; ++i) {
//             long long topRemaining = topPrefix[n] - topPrefix[i + 1];
//             long long bottomCollected = bottomPrefix[i];
//             long long secondRobotScore = max(topRemaining, bottomCollected);
//             result = min(result, secondRobotScore);
//         }

//         return result;
//     }
// };