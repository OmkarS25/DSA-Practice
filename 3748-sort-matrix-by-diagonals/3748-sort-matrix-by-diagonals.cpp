class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        if(n==1) return grid;
        vector<int> extra;
        // Botton Left Triagle
        for(int row=0; row<n; row++){
            for(int i=row, j=0; i<n && j<n; i++, j++){
                extra.push_back(grid[i][j]);
            }
            sort(extra.begin(), extra.end(), greater<int>());
            for(int i=row, j=0; i<n && j<n; i++, j++){
                grid[i][j] = extra[0];
                extra.erase(extra.begin());
            }
        }
        // Top Right Triagle
        for(int col=1; col<n; col++){
            for(int i=0, j=col; i<n && j<n; i++, j++){
                extra.push_back(grid[i][j]);
            }
            sort(extra.begin(), extra.end());
            for(int i=0, j=col; i<n && j<n; i++, j++){
                grid[i][j] = extra[0];
                extra.erase(extra.begin());
            }
        }
        return grid;
    }
};