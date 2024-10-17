class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size(), max_ind = n-1, j = n-1, ans = num;
        while(j >= 0){
            int x = s[j] - '0';
            int maxi = s[max_ind] - '0';
            if(j != max_ind && x <= maxi){
               swap(s[j], s[max_ind]);
               ans = max(ans, stoi(s));
               swap(s[j], s[max_ind]);
            }
            else max_ind=j;
            j--;
        }
        return ans;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();