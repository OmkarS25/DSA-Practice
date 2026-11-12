class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(), ans=1, inc=1, dec=1;
        for(int i=1; i<n; i++){
            bool A = nums[i]>nums[i-1], B = nums[i]<nums[i-1];
            inc = A*inc+1, dec = B*dec+1;
            ans = max(ans, max(inc , dec));
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