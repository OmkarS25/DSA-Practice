class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int s = 0, e = m - 1;
            int firstNeg = m; // default: no negatives
            while(s <= e) {
                int mid = s + (e - s) / 2;
                if(grid[i][mid] < 0) {
                    firstNeg = mid;   // possible candidate
                    e = mid - 1;      // search left for earlier negative
                } else s = mid + 1;      // search right
            }
            ans += (m - firstNeg); // count of negatives in this row
        }
        return ans;
    }
};
