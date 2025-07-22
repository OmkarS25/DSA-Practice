class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int left = 0, currSum = 0, res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            while (s.count(nums[i])) {
                s.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }
            currSum += nums[i];
            s.insert(nums[i]);
            res = max(res, currSum);
        }
        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();