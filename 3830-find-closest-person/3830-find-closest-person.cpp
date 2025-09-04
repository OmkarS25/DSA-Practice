class Solution {
public:
    int findClosest(int x, int y, int z) {
        x = abs(z-x), y = abs(z-y);
        return x==y ? 0 : (x<y ? 1 : 2);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();