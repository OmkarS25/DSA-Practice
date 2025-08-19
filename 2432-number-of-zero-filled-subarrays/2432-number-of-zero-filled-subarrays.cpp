class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        const int n = nums.size();
        long long ans = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) curr++;
            else {
                ans += curr * (curr + 1) / 2;
                curr = 0;
            }
        }
        ans += curr * (curr + 1) / 2;
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();