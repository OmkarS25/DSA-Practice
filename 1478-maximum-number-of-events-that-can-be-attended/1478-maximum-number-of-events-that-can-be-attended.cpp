class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int n = events.size();
        if(n == 1) return 1;
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int res = 0, i = 0, day = 1;

        // Find the last day among all events
        int lastDay = 0;
        for (auto& e : events) lastDay = max(lastDay, e[1]);

        for (day = 1; day <= lastDay; ++day) {
            // Add events starting today
            while (i < n && events[i][0] == day) {
                pq.push(events[i++][1]); // push end day
            }

            // Remove expired events
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }

            // Attend one event today (pick the one that ends earliest)
            if (!pq.empty()) {
                pq.pop();
                res++;
            }
        }

        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();