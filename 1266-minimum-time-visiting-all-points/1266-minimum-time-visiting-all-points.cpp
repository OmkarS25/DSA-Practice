class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& pts) {
        int ans = 0;
        for (int k = 1; k < pts.size(); k++) {
            int dx = abs(pts[k][0] - pts[k - 1][0]);
            int dy = abs(pts[k][1] - pts[k - 1][1]);
            ans += max(dx, dy);
        }
        return ans;
    }
};