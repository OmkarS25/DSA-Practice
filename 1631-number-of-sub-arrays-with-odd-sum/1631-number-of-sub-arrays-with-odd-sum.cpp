class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd=0, even=1, prefixSum=0, ans=0, mod=1e9+7;
        for(auto x:arr){
            prefixSum+=x;
            if(prefixSum&1){
                odd++;
                ans=(ans+even)%mod;
            }else{
                even++;
                ans=(ans+odd)%mod;
            }
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