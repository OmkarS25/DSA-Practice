class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n = nums.size(), right = 0, left = 0;
        long long res = 0;
        while (right < n) {
            k -= m[nums[right++]]++;
            while (k <= 0) k += --m[nums[left++]];
            res += left;
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