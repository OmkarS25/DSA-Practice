class Solution {
public:
    int maximumInvitations(vector<int>& f) {
        int n = size(f), s = 0, m = 0; vector<vector<int>>g(n); vector<int> v(n);
        for (int i = 0; i < n; ++i) if (f[f[i]] != i) g[f[i]].push_back(i);
        auto d = [&](this auto const& d, int i) -> int { 
            int x = 0; for (int j: g[i]) x = max(x, d(j)); return 1 + x;};
        for (int i = 0; i < n; ++i) { 
            if (f[f[i]] == i) { s += d(i); continue; }
            int c = 0, j = i, k = i;
            while (!v[j]) ++c, ++v[j], j = f[j];
            while (j != k) --c, k = f[k];
            m = max(m, c); 
        } return max(s, m);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();