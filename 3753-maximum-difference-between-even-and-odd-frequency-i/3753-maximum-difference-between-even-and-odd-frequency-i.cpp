class Solution {
public:
    int maxDifference(string s) {
        int odd = INT_MIN, even = INT_MAX;
        int freq[26] = {0}; 
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        for(int n : freq) {
            if(n == 0) continue; 
            if(n % 2 == 0) even = min(even, n); 
            else odd = max(odd, n);
        }
        return odd - even;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();