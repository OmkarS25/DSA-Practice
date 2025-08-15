class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1 || n == 4) return true;
        if(n <= 0 || n%2 != 0) return false;
        while(n){
            if(n == 4) return true;
            if(n%4 == 0) n /= 4;
            else return false;
        }
        return true;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();