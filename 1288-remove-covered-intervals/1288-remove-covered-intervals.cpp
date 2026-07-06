class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) return a[0] < b[0];  // start badhta hua
                 return a[1] > b[1];                    // tie pe end ghatta hua
             });

        int removedIntervals = 0;
        int prevEnd = 0;   // ab tak ka sabse bada end (ends hamesha >= 1 hote hain)

        for (const auto& iv : intervals) {
            if (iv[1] > prevEnd) {   // sabse door tak gayi -> rakho
                ++removedIntervals;
                prevEnd = iv[1];
            }
            // warna iv.end <= prevEnd hai, matlab jisne prevEnd set kiya wo isko cover kar rahi hai
        }
        return removedIntervals;
    }
};