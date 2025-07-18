class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int dfs(int i, int k, vector<vector<int>>& events, vector<int>& startDays) {
        if (i == n || k == 0) return 0;
        if (dp[i][k] != -1) return dp[i][k];

        // Binary search to find the next non-overlapping event
        int nextIndex = lower_bound(startDays.begin(), startDays.end(), events[i][1] + 1) - startDays.begin();

        int take = events[i][2] + dfs(nextIndex, k - 1, events, startDays);    // take current event
        int skip = dfs(i + 1, k, events, startDays); // skip current event

        return dp[i][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // Sort by start time
        n = events.size();

        vector<int> startDays;
        for (auto& e : events)
            startDays.push_back(e[0]);

        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));

        return dfs(0, k, events, startDays);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();