class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int mask = 0, ans = 1, i = 0, j = 0;
        while(j < nums.size()){
            while(mask & nums[j]) mask = (mask ^ nums[i++]);
            ans = max(ans, j - i + 1);
            mask |= nums[j++];
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