class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    vector<string> patterns;
    vector<vector<int>> memo;

    // Generate all valid column‑colorings of width m
    void generate(string cur, int rem, char prev) {
        if (rem == 0) {
            patterns.push_back(cur);
            return;          // ← make sure to stop here!
        }
        for (char c : {'R','G','B'}) {
            if (c == prev) continue;
            generate(cur + c, rem - 1, c);
        }
    }

    // Count ways to stack r more rows on top of pattern index i
    int dp(int r, int i, int m) {
        if (r == 0) return 1;
        int &ans = memo[r][i];
        if (ans != -1) return ans; // ← if already computed, reuse
        long long total = 0;
        const string &below = patterns[i];
        // try every possible pattern above
        for (int j = 0; j < (int)patterns.size(); j++) {
            const string &above = patterns[j];
            bool ok = true;
            // must differ in every column
            for (int k = 0; k < m; k++) {
                if (below[k] == above[k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) total = (total + dp(r - 1, j, m)) % MOD;
        }
        return ans = total;
    }

    int colorTheGrid(int m, int n) {
        patterns.clear();
        generate("", m, '.');
        int p = patterns.size();
        // memo dimensions: (rows_remaining from 0..n-1) × (pattern index)
        memo.assign(n, vector<int>(p, -1));

        long long answer = 0;
        // choose bottom-most pattern and stack the rest
        for (int i = 0; i < p; i++) {
            answer = (answer + dp(n - 1, i, m)) % MOD;
        }
        return (int)answer;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();