class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size(), cnt = 0;
        unordered_map<int, long long> fre;
        fre[0]=1;
        long long ans = 0;
        for(int r=0; r<n; r++){
            if(nums[r]%modulo == k) cnt++;
            ans+=fre[((cnt%modulo - k)+modulo)%modulo];
            fre[cnt%modulo]++;
        }
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();