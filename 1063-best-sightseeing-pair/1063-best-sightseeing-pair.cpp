class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0, Prev = values[0];
        for (int j = 1; j < values.size(); j++) {
            ans = max(ans, Prev + values[j] - j);
            Prev = max(Prev, values[j] + j);
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