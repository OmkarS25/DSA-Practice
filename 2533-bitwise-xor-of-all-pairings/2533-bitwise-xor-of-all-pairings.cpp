class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size(), res=0;
        if(s1 % 2 == 0 && s2 % 2 == 0) return 0;
        if(s2 % 2 != 0) {
            for(int x:nums1) res ^= x;
        }
        if(s1 % 2 != 0) {
            for(int x:nums2) res ^= x;
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