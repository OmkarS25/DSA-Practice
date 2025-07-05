class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int ans = -1;
        for(int a : arr) mp[a]++;
        for(const auto & [key, value] : mp){
            if(key == value) ans = max(ans, key);
        }
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();