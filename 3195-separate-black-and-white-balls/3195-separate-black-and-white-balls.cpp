class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        int black = 0; 
        for(int i=0; i<s.length(); i++){
            if(s[i] == '0') res += (long long) black;
            else black++;
        }
        return res;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();