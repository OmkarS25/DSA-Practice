class Solution {
public:
    string answerString(string word, int num) {
        if(num == 1) return word;
        int n = word.size(), len = n - num + 1;
        string ans = "";
        
        for(int i = 0; i < n; i++) {
            ans = max(ans, word.substr(i, len));
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