class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int index = 0, res = 1;
        for(int i=0; i<n; i++){
            if(nums[i] - nums[index] > k){
                res++;
                index = i;
            }
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