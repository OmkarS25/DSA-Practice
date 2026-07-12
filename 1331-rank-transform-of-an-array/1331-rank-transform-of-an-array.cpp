#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        const int n = arr.size();
        if (n == 0) return {};

        vector<int> res(n);
        vector<pair<int,int>> temp(n);

        for (int i = 0; i < n; i++) 
            temp[i] = {arr[i],i};

        sort(temp.begin(),temp.end(),[](pair<int,int> &a , pair<int,int> &b) {
            return a.first < b.first;
        });

        res[temp[0].second] = 1;
        
        for (int i = 1; i < n; i++) {
            res[temp[i].second] = res[temp[i - 1].second] + ((temp[i].first == temp[i - 1].first) ? 0 : 1);
        }
        return res;
    }
};