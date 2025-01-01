class Solution {
public:
    int maxScore(string s) {
        int maxi = 0;
        int leftZero = 0, rightOne = 0;

        for (auto digit : s) {
            if (digit == '1') rightOne++;
        }

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') leftZero++;
            else rightOne--;
            maxi = max(maxi, leftZero + rightOne);
        }
        return maxi;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();