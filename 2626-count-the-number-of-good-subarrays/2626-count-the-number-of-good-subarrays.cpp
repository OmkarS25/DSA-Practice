class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size(), srt = 0, cur = 0;
        map <int, int> hash;
        for (int i = 0; i < n; i++) {
            cur += hash[nums[i]];
            hash [nums[i]] ++;
            while (cur >= k) {
                res += (n - i); 
                cur -= hash[nums[srt]] - 1;
                hash[nums[srt++]] --;            
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