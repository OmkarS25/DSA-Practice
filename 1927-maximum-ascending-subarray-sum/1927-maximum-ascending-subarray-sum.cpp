class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0], sum = nums[0];
        for(int i=1; i < nums.size(); i++){
            sum = (nums[i] > nums[i-1]) * sum + nums[i];
            maxSum = max(maxSum, sum);
        }
        return max(maxSum, sum);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();