class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), currentOR = 0, left = 0, minLength = INT_MAX;
        vector<int> bitCount(32, 0);
        for (int right = 0; right < n; right++) {
            currentOR |= nums[right];
            for (int bit = 0; bit < 32; bit++) if (nums[right] & (1 << bit)) bitCount[bit]++;
            while (left <= right && currentOR >= k) {
                minLength = min(minLength, right - left + 1);
                int updatedOR = 0;
                for (int bit = 0; bit < 32; bit++) {
                    if (nums[left] & (1 << bit)) bitCount[bit]--;
                    if (bitCount[bit] > 0) updatedOR |= (1 << bit);
                }
                currentOR = updatedOR;
                left++;
            }
        }
        return minLength == INT_MAX ? -1 : minLength;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();