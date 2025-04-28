class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        const int n = nums.size();
        long ans = 0, sum = 0;
        int left = 0;
        for(int right=0;right<n;right++){
            sum += nums[right];
            while(sum * (right - left + 1) >= k) sum -= nums[left++];
            ans += right - left + 1;
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