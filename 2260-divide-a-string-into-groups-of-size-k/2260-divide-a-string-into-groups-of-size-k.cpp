class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        const int n = s.size();
        vector<string> v;
        for (int i = 0; i < n; i += k) {
            string str = s.substr(i, k);
            while (str.size() < k) str += fill;
            v.push_back(str);
        }
        return v;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();