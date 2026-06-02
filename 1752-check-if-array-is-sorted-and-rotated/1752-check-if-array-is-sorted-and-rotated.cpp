class Solution {
public:
    bool check(vector<int>& nums) {
        const int n=nums.size();
        int cntD=0;
        for(int i=1; i<n && cntD<=1; i++){
            if (nums[i]<nums[i-1]) cntD++;
        }
        return (nums[0]>=nums.back() && cntD==1) || cntD==0;
        
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();