class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size(), ans=INT_MIN, left=0;
        sort(nums.begin(),nums.end());
        for(int right=0;right<n;right++){
            while(nums[right]-nums[left] > 2*k){
                left++;
            }
            ans = max(ans, abs(left-right)+1);
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