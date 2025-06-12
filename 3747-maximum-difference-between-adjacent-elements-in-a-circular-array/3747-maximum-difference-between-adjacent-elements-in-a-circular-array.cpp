class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        const int n = nums.size();
        int res = abs(nums[0] - nums[n-1]);
        for(int i=1; i<n; i++){
            res = max(res, abs(nums[i] - nums[i-1]));
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