class Solution {
public:
    int maxGold(vector<vector<int>>&grid, int i, int j, int rows, int cols){
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
            return 0;
        }
        // Mark as visited
        int curr = grid[i][j];
        grid[i][j] = 0;
        // Find the max values
        int left = maxGold(grid,i,j-1,rows,cols);
        int right = maxGold(grid,i,j+1,rows,cols);
        int up = maxGold(grid,i-1,j,rows,cols);
        int down = maxGold(grid,i+1,j,rows,cols);
        // Mark as not visited again for other numbers
        grid[i][j] = curr;
        return curr + max({left, right, up, down});

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        int maxgold=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] != 0){
                    maxgold = max(maxgold, maxGold(grid,i,j,rows,cols));
                }
            }
        }
        return maxgold;
    }
};