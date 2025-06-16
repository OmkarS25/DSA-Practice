class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int cur_min = INT_MAX, max_diff = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - cur_min > max_diff) {
                // cout << i << " : " << nums[i] << endl;
                max_diff = nums[i] - cur_min;
            }
            cur_min = min(cur_min, nums[i]);
        }
        return max_diff == 0 ? -1 : max_diff;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();