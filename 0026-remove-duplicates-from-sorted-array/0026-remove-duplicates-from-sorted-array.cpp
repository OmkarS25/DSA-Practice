class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[j] != nums[i]) nums[++j] = nums[i];
        }
        return j+1;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();