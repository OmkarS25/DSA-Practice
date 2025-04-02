class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long max_i=nums[0], max_diff=nums[0]-nums[1], ans=0;
        for(int k=2;k<n;k++){
            ans = max(ans,max_diff*nums[k]);
            max_i = max(max_i,(long long)nums[k-1]);
            max_diff = max(max_diff,max_i-nums[k]);
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