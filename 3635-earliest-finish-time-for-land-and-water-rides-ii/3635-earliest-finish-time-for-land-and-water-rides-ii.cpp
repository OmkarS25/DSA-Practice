class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        const int m = landStartTime.size(), n = waterStartTime.size();
        int mintime = INT_MAX, minlandfinish = INT_MAX;
        for (int i = 0; i < m; i++) {
            minlandfinish = min(minlandfinish, landStartTime[i] + landDuration[i]);
        }
        for (int j = 0; j < n; j++) {
            mintime = min(mintime, max(minlandfinish, waterStartTime[j]) + waterDuration[j]);
        }
        int minwaterfinish = INT_MAX;
        for (int i = 0; i < n; i++) {
            minwaterfinish = min(minwaterfinish, waterStartTime[i] + waterDuration[i]);
        }
        for (int j = 0; j < m; j++) {
            mintime = min(mintime, max(minwaterfinish, landStartTime[j]) + landDuration[j]);
        }
        return mintime;
    }
};