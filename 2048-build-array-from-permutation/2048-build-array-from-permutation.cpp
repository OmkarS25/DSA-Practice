class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        const int size = nums.size();
        vector<int> ans (size, 0);
        for(int i=0; i<size; i++) ans[i] = nums[nums[i]];
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();