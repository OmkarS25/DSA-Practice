class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i : nums){
            int count = 0;
            while(i>=10) {
                i/=10;
                count += 1;
            }
            if(count&1) ans++;
        }
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();