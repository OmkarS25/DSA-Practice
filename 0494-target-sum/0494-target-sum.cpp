class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        function<int(int, int)> dfs = [&](int i, int sum) -> int {
            if (i == nums.size()) return sum == target ? 1 : 0;
            string key = to_string(i) + "," + to_string(sum);
            if (memo.count(key)) return memo[key];
            return memo[key] = dfs(i + 1, sum + nums[i]) + dfs(i + 1, sum - nums[i]);
        };
        return dfs(0, 0);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();