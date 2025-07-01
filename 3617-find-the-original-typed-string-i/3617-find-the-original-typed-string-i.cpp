class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1, n = word.length();
        for(int i=1; i<n; i++){
            if(word[i] == word[i-1]) ans++;
        }
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();