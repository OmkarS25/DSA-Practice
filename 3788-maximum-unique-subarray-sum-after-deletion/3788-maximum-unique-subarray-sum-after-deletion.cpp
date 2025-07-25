class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        if(ans < 0 || ans == 0 || ans == 1) return ans;
        else ans = 0;
        set<int> unique;
        for(int a : nums)
            if(a > 0) unique.insert(a);
        for(int a : unique) ans += a;
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();