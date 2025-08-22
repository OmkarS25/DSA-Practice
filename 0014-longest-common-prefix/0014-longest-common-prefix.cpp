class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int minSize = INT_MAX;
        for(const auto &str : s) minSize = min(minSize, static_cast<int>(str.size()));
        int count = 0;
        for(int i=0; i<minSize; i++){
            char ch = s[0][i];
            bool broken = false;
            for(int j=1; j<s.size(); j++){
                if(s[j][i] != ch) {
                    broken = true;
                    break;
                }
            }
            if(broken) break;
            count++;
        }
        return s[0].substr(0, count);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();