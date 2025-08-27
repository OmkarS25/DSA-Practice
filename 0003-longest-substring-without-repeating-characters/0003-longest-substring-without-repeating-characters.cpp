class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int left = 0, ans = 0;
        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            if (mp.find(ch) != mp.end() && mp[ch] >= left)
                left = mp[ch] + 1;
            mp[ch] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const bool _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();