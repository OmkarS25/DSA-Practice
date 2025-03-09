class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0, cnt = 1, n = colors.size();
        for(int i = 1; i < (n + k - 1); i++) {
            if(colors[i % n] != colors[(i - 1) % n]) cnt++;
            else cnt = 1;
            if(cnt >= k) ans++;
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