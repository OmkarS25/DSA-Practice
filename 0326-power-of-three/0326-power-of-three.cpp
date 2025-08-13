class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0 || n%2 == 0) return false;
        if(n == 1 || n == 3) return true;
        while(n){
            if(n == 3) return true;
            if(n%3 == 0) n /= 3;
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