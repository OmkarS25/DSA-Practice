class Solution {
public:
    long long pickGifts(vector<int> gifts, int k) {
        for(int i=0; i<k; i++){
            sort(gifts.begin(), gifts.end(), greater<int>());
            gifts[0] = static_cast<int>(sqrt(gifts[0]));
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();