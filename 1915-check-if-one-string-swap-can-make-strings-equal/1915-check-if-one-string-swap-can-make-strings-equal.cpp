class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i = -1, j = -1, count = 0;
        for (int k = 0; k < s1.length(); k++) {
            if (s1[k] != s2[k]) {
                count++;
                if (i == -1) i = k;
                else if (j == -1) j = k;
            }
        }
        if (count == 0) return true;
        else if (count == 2 && s1[i] == s2[j] && s1[j] == s2[i]) return true;
        else return false;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();