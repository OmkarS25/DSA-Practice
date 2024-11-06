class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size(), start = 0;
        for (int i = 1; i < n; i++) {
            int a = __builtin_popcount(nums[i - 1]);
            int b = __builtin_popcount(nums[i]);
            if (a != b) {
                sort(nums.begin() + start, nums.begin() + i);
                start = i;
            }
        }
        sort(nums.begin() + start, nums.end());
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();