class Solution {
    int maxi, mod=1e9+7;
    vector<vector<int>> dp;
    long long lcs(int i, int n, int x, int sum){
        if(sum == n) return 1;
        if(i >= maxi)
            if(sum == n) return 1;
            else return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        if(sum+pow(i,x) <= n) 
            return dp[i][sum] = lcs(i+1,n,x,sum)%mod + lcs(i+1,n,x,sum+pow(i,x))%mod;
        else return dp[i][sum] = lcs(i+1,n,x,sum)%mod;
    }
public:
    int numberOfWays(int n, int x) {
        maxi = 1;
        while(pow(maxi,x) <= n){
            maxi++;
        }
        dp = vector<vector<int>> (maxi,vector<int>(n+1,-1));
        return int(lcs(1,n,x,0)%mod);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();