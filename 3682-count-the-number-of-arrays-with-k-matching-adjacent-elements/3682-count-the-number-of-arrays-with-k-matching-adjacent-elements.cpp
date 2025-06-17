class Solution {
public:
    long long power(long long x, int n, long long res = 1){
        for(int M = 1e9+7; n; n/=2, x = x*x%M)
            if(n%2) res = res*x%M;
        return res;
    } // nothing new, just for self practice

    int countGoodArrays(int n, int m, int k) {
        long long M = 1e9+7, MX = 1e5, fact[100000] = {1}, inv_fact[100000] = {};
        
        for(int i=1; i<MX; ++i) 
            fact[i] = fact[i-1]*i%M;

        inv_fact[MX-1] = power(fact[MX-1], M-2); // (1/a)%p = pow(a, p-2);
        
        for(int i=MX-1; i; --i) 
            inv_fact[i-1] = inv_fact[i]*i%M;
        
        auto comb = [&](int n, int r){
            return fact[n] * inv_fact[r]%M * inv_fact[n-r]%M;
        };

        return comb(n-1, k) * m%M * power(m-1, n-1-k)%M;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();