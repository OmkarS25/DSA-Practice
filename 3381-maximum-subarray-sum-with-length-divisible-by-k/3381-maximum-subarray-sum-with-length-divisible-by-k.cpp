class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<long long> min_prefix(k, LLONG_MAX / 2);
        long long prefix = 0;
        long long res = LLONG_MIN;
        min_prefix[k - 1] = 0;
        for (int i = 0; i < n; i++){
            prefix += nums[i];
            long long& mod_min = min_prefix[i % k];
            res = max(res, prefix - mod_min);
            mod_min = min(prefix, mod_min);
        }
        return res;
    }
};