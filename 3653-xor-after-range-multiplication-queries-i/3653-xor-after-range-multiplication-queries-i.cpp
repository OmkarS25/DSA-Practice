const int MOD = 1000000007;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (const auto& q : queries) {
            int idx = q[0], r = q[1], k = q[2], v = q[3];
            while (idx <= r) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
                idx += k;
            }
        }

        int ans = 0;
        for (int num : nums) {
            ans ^= num;
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