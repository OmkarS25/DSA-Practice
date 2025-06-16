class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        const int n = nums.size();
        int ans = -1;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int tmp = -1;
                if(nums[i] < nums[j]) tmp = nums[j] - nums[i];
                ans = max(tmp, ans);
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