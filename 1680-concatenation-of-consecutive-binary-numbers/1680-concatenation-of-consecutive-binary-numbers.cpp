constexpr int mod=1e9+7, N=1e5+1;
uint64_t dp[N];
int End=1;
class Solution {
public:
    static int concatenatedBinary(int n) {
        if (n<End) return dp[n];
        uint64_t ans=dp[End-1];// computation from the last end
        for(unsigned x=End; x<=n; x++){
            const int bw=32-countl_zero(x);
            ans=(ans<<bw)+x;
            if (ans>=mod) ans%=mod;
            dp[End++]=ans;// store to dp[End], & End++
        }
        return ans;
    }
};