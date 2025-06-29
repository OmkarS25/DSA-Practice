class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<pair<int, int>> v;
        
        for (int i = 0; i < n; ++i) v.emplace_back(nums[i], i);

        sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.first > b.first; });

        v.resize(k);

        sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second < b.second; });

        vector<int> res;
        for (auto& [val, _] : v) res.push_back(val);

        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();