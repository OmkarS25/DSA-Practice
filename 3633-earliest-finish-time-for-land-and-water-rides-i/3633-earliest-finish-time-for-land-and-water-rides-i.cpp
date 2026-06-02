class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        const int n = landStartTime.size(), m = waterStartTime.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // land to Water
                int srt1 = landStartTime[i];
                int duration1 = srt1 + landDuration[i];
                int w_srt = max(duration1, waterStartTime[j]);
                ans = min(ans, w_srt + waterDuration[j]);

                // Water to land
                int srt2 = waterStartTime[j];
                int duration2 = srt2 + waterDuration[j];
                int l_srt = max(duration2, landStartTime[i]);
                ans = min(ans, l_srt + landDuration[i]);
            }
        }

        return ans;
    }
};