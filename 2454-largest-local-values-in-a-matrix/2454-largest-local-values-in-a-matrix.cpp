class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2));
        for(int i=1; i<n-1; i++){
            for(int j=1; j<n-1; j++){
                int maxVal = INT_MIN;
                // Iterate over the poolsized matrix
                for (int k = i-1; k <= i+1; k++) {
                    for (int l = j-1; l <= j+1; l++) {
                        maxVal = max(maxVal, grid[k][l]);
                    }
                }
                res[i-1][j-1] = maxVal;
            }
        }
        return res;
    }
};