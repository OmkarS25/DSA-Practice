class Solution {
public:
    bool isPowerOfThree(int n) {
        const int max_pow = 1162261467;
        return n > 0 && max_pow % n == 0;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();