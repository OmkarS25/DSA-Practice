auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int findComplement(int num) {
        if(num == 1) return 0;
        int ans = 0, power = 1;
        while (num) {
            if (!(num & 1)) ans += power;
            num >>= 1;
            power <<= 1;
        }
        return ans;
    }
};
