#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    bool helper(int index, const string & s2, unordered_map<char, int> map, int len) {
        for (int i = index; i < index + len; i++) {
            if (i >= s2.size() || map[s2[i]] == 0) return false;
            map[s2[i]]--;  
        }
        return true;  
    }

    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> map;
        bool ans = false;
        int len = s1.size();
        if(len > s2.size()) return false;
        for(char ch: s1) map[ch]++;
        for(int i = 0; i <= s2.size() - len; i++) {
            if (map[s2[i]]) {
                unordered_map<char, int> temp = map;
                if (helper(i, s2, temp, len)) return true;  
            }
        }
        return false;
    }
};
