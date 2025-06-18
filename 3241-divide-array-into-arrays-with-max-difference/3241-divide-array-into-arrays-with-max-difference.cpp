class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        const int n = nums.size();
        for (int i=0; i<n; i+=3) {
            if (nums[i+2] - nums[i] > k) {
                return {};
            }
            ans.push_back({nums[i], nums[i+1], nums[i+2]});
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