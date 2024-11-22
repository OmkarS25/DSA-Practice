class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int tc = 0; 
        map<vector<int>, int> mp; 

        for (auto vec : matrix) {
            int x = vec[0] == 1; 
            for (int i = 0; i < vec.size(); ++i)
                vec[i] = x ^ vec[i]; 
            mp[vec]++; 
        }

        for (auto &x : mp)
            tc = max(tc, x.second);

        return tc;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();