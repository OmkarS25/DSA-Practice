class Solution {
    static constexpr int MOD = int(1e9+7);

public:
    int checkRecord(int n) {
        if (n == 1) {
            return 3;
        }

        vector<int> f(n+1), g(n+1);
        f[0] = g[0] = 1;
        f[1] = 3;
        f[2] = 8;
        g[1] = 2;
        g[2] = 4;
        for (int i = 3; i <= n; ++i) {
            g[i] = ((g[i-1] + g[i-2]) % MOD + g[i-3]) % MOD;
            f[i] = (((f[i-1] + f[i-2]) % MOD + f[i-3]) % MOD + g[i]) % MOD;
        }
        return f[n];
    }
};

namespace {
    const auto __ = [] {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        return 0;
    }();
}

// class Solution {
// public:
//     int checkRecord(int n) {
//         const int MOD = 1000000007;
//         vector<vector<int>> dp_last(2, vector<int>(3, 0)); // previous state
//         vector<vector<int>> dp_current(2, vector<int>(3, 0)); // current state

//         dp_last[0][0] = 1; // empty string

//         for (int i = 0; i < n; i++) {
//             for (int count_a = 0; count_a < 2; count_a++) {
//                 for (int count_l = 0; count_l < 3; count_l++) {
//                     // choose "P"
//                     dp_current[count_a][0] = (dp_current[count_a][0] + dp_last[count_a][count_l]) % MOD;
//                     // choose "A"
//                     if (count_a == 0) {
//                         dp_current[count_a + 1][0] = (dp_current[count_a + 1][0] + dp_last[count_a][count_l]) % MOD;
//                     }
//                     // Choose "L"
//                     if (count_l < 2) {
//                         dp_current[count_a][count_l + 1] = (dp_current[count_a][count_l + 1] + dp_last[count_a][count_l]) % MOD;
//                     }
//                 }
//             }
//             dp_last = dp_current; // Reference current to previous
//             dp_current = vector<vector<int>>(2, vector<int>(3, 0)); // make new current
//         }

//         // Sum up the counts for all combinations of length 'n' with different count_a and count_l.
//         int res = 0;
//         for (int count_a = 0; count_a < 2; count_a++) {
//             for (int count_l = 0; count_l < 3; count_l++) {
//                 res = (res + dp_last[count_a][count_l]) % MOD;
//             }
//         }
//         return res;
//     }
// };

/* https://leetcode.com/problems/student-attendance-record-ii/solutions/5209610/detailed-explanation-2-approaches-extremely-simple-and-effective-beginner-friendly*/

// #pragma clang attribute push (__attribute__((no_sanitize("address","undefined"))), apply_to=function)

// const int mod = 1E9 + 7;

// int dp[2][3][4], ts;
// array<int, 2> t[1024];

// ofstream out("user.out");

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0);
//     for (int n; cin >> n; ts++) t[ts] = {n, ts};
//     sort(t, t + ts, [](auto& x, auto& y) { return x[0] < y[0]; });
    
//     for (int a : {0, 1})
//         for (int l : {0, 1, 2})
//             dp[0][a][l] = 1;
    
//     int ti = 0;
//     for (int i = 1, lim = t[ts - 1][0]; i <= lim; i++) {
// #pragma unroll
//         for (int a : {0, 1}) {
// #pragma unroll
//             for (int l : {0, 1, 2}) {
//                 auto& ans = dp[i & 1][a][l];
//                 ans = dp[~i & 1][a][0];
//                 ans += dp[~i & 1][a + 1][0];
//                 ans -= (ans >= mod) * mod;
//                 ans += dp[~i & 1][a][l + 1];
//                 ans -= (ans >= mod) * mod;
//             }
//         }
//         while (t[ti][0] == i)
//             t[ti++][0] = dp[i & 1][0][0];
//     }
//     sort(t, t + ts, [](auto& x, auto& y) { return x[1] < y[1]; });
//     for (int i = 0; i < ts; i++)
//         out << t[i][0] << "\n";
// }

// #define main main_

// class Solution {
// public:
//     int checkRecord(int n) {
//         return 0;
//     }
// };

// #pragma clang attribute pop