class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return a[1] < b[1];  // sort by end day
        });

        set<int> available;
        // fill available days
        for (int i = 1; i <= 100000; ++i) available.insert(i);

        int res = 0;
        for (auto& event : events) {
            int start = event[0], end = event[1];
            auto it = available.lower_bound(start);
            if (it != available.end() && *it <= end) {
                available.erase(it);
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