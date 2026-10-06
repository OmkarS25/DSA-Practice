#pragma GCC optimize ("Ofast", "-ffloat-store", "O3", "unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0, close=0;
        for(auto ch : s) (ch == '(') ? (open++) : ((open > 0) ? open-- : close++);
        return open + close;
    }
};