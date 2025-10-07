class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int n = rains.size();
        vector<int> res(n, -1);
        unordered_map<int, int> lakeLastFilled;
        set<int> dryDays;  // stores indices of dry days

        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                dryDays.insert(i);  // mark this day as available for drying
            } else {
                if (lakeLastFilled.count(lake)) {
                    // Find the earliest dry day after the last time this lake was filled
                    auto it = dryDays.upper_bound(lakeLastFilled[lake]);
                    if (it == dryDays.end()) return {};  // no valid dry day found
                    res[*it] = lake;  // dry this lake on that day
                    dryDays.erase(it);  // remove used dry day
                }
                lakeLastFilled[lake] = i;  // update last filled day
            }
        }

        // Fill remaining dry days with arbitrary lake (e.g., 1)
        for (int day : dryDays) res[day] = 1;

        return res;
    }
};
