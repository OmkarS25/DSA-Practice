class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 1) {
            if(n % 3 == 1) n--;
            if(n%3==0) n = n / 3;
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