#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int minSwaps(string s) {
        int count = 0, n = s.size();
        for(char & ch: s){
            if(ch == '[') count++;
            else if(count > 0) count--;
        }
        return (count+1)/2;
    }
};