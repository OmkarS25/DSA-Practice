class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = 1;
            for (int j = i-1; j >= 0 && (nums[j] != (nums[i] | nums[j])); j--) {
                nums[j] = nums[i] | nums[j];
                ans[j] = i - j + 1;
            }
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