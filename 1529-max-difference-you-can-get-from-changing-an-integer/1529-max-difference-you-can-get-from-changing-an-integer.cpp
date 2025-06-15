class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Generate max number: replace first non-9 digit with 9
        string maxStr = s;
        char toReplaceMax = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax)
            for (char &ch : maxStr)
                if (ch == toReplaceMax)
                    ch = '9';

        // Generate min number
        string minStr = s;
        char toReplaceMin = 0, replaceWithMin = 0;
        if (s[0] != '1') {
            toReplaceMin = s[0];
            replaceWithMin = '1';
        } 
        else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    replaceWithMin = '0';
                    break;
                }
            }
        }
        if (toReplaceMin)
            for (char &ch : minStr)
                if (ch == toReplaceMin) ch = replaceWithMin;

        return stoi(maxStr) - stoi(minStr);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();