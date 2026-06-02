class Solution {
public:
    int dp[1001];
    int n;
    int find(int i, vector<int>& nums, int t) {
        if (i == n - 1) return 0;
        if (dp[i] != -1) return dp[i];
        int res = INT_MIN;
        for (int j = i + 1; j < n; j++) {
            if (abs(nums[i] - nums[j]) <= t) {
                int c = find(j, nums, t);
                if (c != INT_MIN) res = max(res, 1 + c);
            }
        }
        return dp[i] = res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        int ans = find(0, nums, target);
        return ans == INT_MIN ? -1 : ans;
    }
};