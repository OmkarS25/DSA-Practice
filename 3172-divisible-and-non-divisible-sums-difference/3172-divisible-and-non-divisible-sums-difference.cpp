class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = 0;
        for(int i=1; i<=n; i++){
            if(i%m == 0) sum = sum - i;
            else sum = sum + i;
        }
        return sum;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();