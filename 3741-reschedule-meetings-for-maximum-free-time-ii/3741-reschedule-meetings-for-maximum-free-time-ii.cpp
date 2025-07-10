class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        const int n = startTime.size();
        int ans = 0;

        vector<int> gaps(n+1);
        gaps[0] = startTime[0];
        for(int i = 1; i < n; i++){
            gaps[i] = startTime[i] - endTime[i-1];
        }
        gaps[n] = eventTime - endTime[n-1];

        vector<int> maxL(n+1);
        vector<int> maxR(n+1);
        maxL[0] = gaps[0];

        for(int i = 1; i <= n; i++){
            maxL[i] = max(maxL[i-1], gaps[i]);
        }
        maxR[n] = gaps[n];
        for(int i = n-1; i >= 0; i--){
            maxR[i] = max(maxR[i+1], gaps[i]);
        }

        for(int i = 0; i < n; i++){
            int len = endTime[i] - startTime[i];
            int sum = gaps[i] + gaps[i+1];
            int bestGap = 0;

            if(i > 0) bestGap = max(bestGap, maxL[i-1]);
            if(i+2 <= n) bestGap = max(bestGap, maxR[i+2]);
            if(len <= bestGap) ans = max(ans, sum + len);
            else ans = max(ans, sum);
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