class Solution {
public:
    long long coloredCells(int n) {
        return pow(n,2) + pow(n-1,2);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();