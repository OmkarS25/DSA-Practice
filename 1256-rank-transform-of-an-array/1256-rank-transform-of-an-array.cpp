#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s;
        for(int& a : arr) s.insert(a);
        set<int>::iterator it;
        unordered_map<int, int> values;
        int i=1;
        for (it = s.begin(); it != s.end(); it++, i++) values[*it] = i;
        for(int i=0; i< arr.size(); i++) arr[i] = values[arr[i]];
        return arr;
    }
};