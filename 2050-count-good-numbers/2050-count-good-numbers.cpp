long long mod = 1e9 + 7;

class Solution {
public:
    long long power(long long x, long long n) {
        // base case
        if (n == 1) {
            return x;
        }
        //even power
        if (n % 2 == 0) {
            long long powNby2 = power(x, n / 2) % mod;
            return (powNby2 * powNby2) % mod;
        }
        //odd power
        else {
            long long powNby2 = power(x, n / 2) % mod;
            return (powNby2 * powNby2 * x) % mod;
        }
    }

    int countGoodNumbers(long long n) {

        if (n == 1)
            return 5;

        // 5 possibilities for even indexes and 4 for odd
        long long even = 1, odd = 1;

        // perfect split
        if (n % 2 == 0) {
            even = odd = n / 2;
        }
        // since 1st index is even we get one extra even index
        else {
            even = n / 2 + 1;
            odd = n / 2;
        }
        return (power(5, even) * power(4, odd)) % mod;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();