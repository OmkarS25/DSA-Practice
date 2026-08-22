class Solution {
public:
    typedef long long ll;
    ll f(ll mid, vector<int> &coins){
        ll n = coins.size();
        ll ans = 0;
        ll temp = (1<<n) - 1; // for getting all subsets for inclusion and exclusion
        for(int mask = 1;mask <= temp;mask++){
            ll currlcm = 1;
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(mask & (1<<j)){
                    currlcm = lcm(currlcm, coins[j]);
                    cnt++;
                }
            }
            if(cnt & 1) ans += mid/currlcm;
            else ans -= mid/currlcm;
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll lo = 1;
        ll hi = 2e9*25;
        ll ans = -1;
        while(lo<= hi){
            ll mid = lo + (hi-lo)/2;
            if(f(mid, coins) < k) lo = mid+ 1;
            else {
                ans = mid;
                hi = mid-1;
            }
        }
        return ans;
    }
};