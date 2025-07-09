class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        const int n = startTime.size();
        int maxi = 0;
        vector<int> duration(n);
        for (int i = 0; i < n; i++) {
            duration[i] = endTime[i] - startTime[i];
        }
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + duration[i];
        }
        for (int i = k - 1; i < n; i++) {
            int totalTime = sum[i + 1] - sum[i - k + 1];
            int left = (i - k >= 0) ? endTime[i - k] : 0;
            int right = (i + 1 < n) ? startTime[i + 1] : eventTime;
            int gap = right - left - totalTime;
            maxi = max(maxi, gap);
        }
        return maxi;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();
