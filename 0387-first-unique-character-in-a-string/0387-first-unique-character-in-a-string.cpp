class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;
        for(char& ch:s) freq[ch]++;
        for(int i=0; i<s.size(); i++) if(freq[s[i]] == 1) return i;
        return -1;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();