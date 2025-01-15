class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int countBitsNum2 = 0, temp2 = num2;
        while (temp2 > 0) {
            if (temp2 % 2 != 0) countBitsNum2++;
            temp2 = temp2 >> 1;
        }
        int res = 0;
        for (int i = 31; i > 0 && countBitsNum2 > 0; i--) {
            if (num1 & (1 << i)) {
                res |= (1 << i);
                countBitsNum2--;
            }
        }
        for (int i = 0; i < 32 && countBitsNum2 > 0; i++) {
            if (!(res & (1 << i))) {
                res |= (1 << i);
                countBitsNum2--;
            }
        }
        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();