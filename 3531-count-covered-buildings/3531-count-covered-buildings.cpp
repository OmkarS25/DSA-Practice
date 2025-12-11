class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,int> rmin, rmax, cmin, cmax;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            if (!rmin.count(x)) rmin[x] = rmax[x] = y;
            else rmin[x] = min(rmin[x], y), rmax[x] = max(rmax[x], y);

            if (!cmin.count(y)) cmin[y] = cmax[y] = x;
            else cmin[y] = min(cmin[y], x), cmax[y] = max(cmax[y], x);
        }

        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            if (rmin[x] < y && rmax[x] > y && cmin[y] < x && cmax[y] > x) ans++;
        }
        return ans;
    }
};