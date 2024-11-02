class Solution {
public:
    bool isCircularSentence(string s) {
        const int n = s.size();
        if(n == 1) return true;
        if(s[0] != s[n-1]) return false;
        for(int i=0; i<n-1; i++){
            if(s[i] == ' ') {
                if(s[i-1] != s[i+1]) return false;
            }
        }
        return true;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();