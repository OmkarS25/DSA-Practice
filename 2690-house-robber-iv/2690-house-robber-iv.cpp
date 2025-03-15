class Solution {
public:
    int minCapability(vector<int>& nums, int k){
        int n = nums.size(), l = 1, r = 1e9, mid;
        auto chk = [&](int c, int cnt = 0) -> bool{
            for (int i = 0; i < n; ++i)
                if (nums[i] <= c) cnt++, i++;
            return cnt >= k;
        };
        while (l <= r){
            mid = l + (r - l) / 2;
            if (chk(mid)) r = mid - 1;
            else l = mid + 1;
        }
        return r + 1;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();