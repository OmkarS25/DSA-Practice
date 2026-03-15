typedef long long ll;
class Fancy {
private:
    vector<int> v;
    ll sum = 0, mul = 1, mod = 1e9 + 7;
    ll power(ll base, ll exp) {
        ll ans = 1;
        base %= mod;
        while (exp) {
            if (exp & 1) ans = (ans * base) % mod;
            exp /= 2;
            base = (base * base) % mod;
        }
        return ans;
    }
    ll modInverse(ll n) { return power(n, mod - 2); }

public:
    Fancy() {}
    void append(int val) { v.push_back(ll(((val - sum + mod) % mod * modInverse(mul)) % mod)); }
    void addAll(int inc) { sum = (sum + inc) % mod; }
    void multAll(int m) { mul = (mul * m) % mod, sum = (sum * m) % mod; }
    int getIndex(int idx) { return (idx >= v.size()) ? -1 : ((v[idx] * mul + sum) % mod); }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */