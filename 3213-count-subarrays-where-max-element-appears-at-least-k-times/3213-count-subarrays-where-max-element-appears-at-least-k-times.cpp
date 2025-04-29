class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int a=*max_element(nums.begin(), nums.end());
        int n=nums.size(), cur=0, i=0;
        long long res=0;
        for(int j=0;j<n;j++) {
            cur+=nums[j]==a;
            while(cur>=k) cur-=nums[i++]==a;
            res+=i;
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