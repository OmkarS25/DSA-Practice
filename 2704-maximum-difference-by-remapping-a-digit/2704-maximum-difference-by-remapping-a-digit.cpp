class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num), maxStr = s, minStr = s;
        bool minDone = 0, maxDone = 0;
        for (char c : s) {
            if (c != '9' && !maxDone) {
                for (char &ch : maxStr) if (ch == c) ch = '9';
                maxDone = true;
            }
            if (c != '0' && !minDone) {
                for (char &ch : minStr) if (ch == c) ch = '0';
                minDone = true;
            }
            if (minDone && maxDone) break;
        }
        return (stoi(maxStr) - stoi(minStr));
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();