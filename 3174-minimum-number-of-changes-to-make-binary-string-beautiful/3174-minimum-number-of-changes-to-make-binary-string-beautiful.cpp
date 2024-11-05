class Solution {
public:
    int minChanges(string s) {
        const int n = s.size();
        int res = 0;
        for(int i=0; i<n; i+=2) if(s[i] != s[i+1]) res++;
        return res;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();