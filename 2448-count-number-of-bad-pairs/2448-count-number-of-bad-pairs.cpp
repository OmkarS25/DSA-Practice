class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        const int n = nums.size();
        long long ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - i;
        }
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                ans += mp[nums[i]];
            }
            mp[nums[i]] += 1;
        }
        long long total = 1LL*n*(n-1)/2;
        return total-ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();