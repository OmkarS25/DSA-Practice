class Solution {
public:
    void dfs(vector<vector<int>> &grid , int i, int j, int &li, int &lj){
        int row = grid.size(), col = grid[0].size();
        if(i<0 || i>=row || j<0 || j>= col || grid[i][j] == 0) return;

        grid[i][j] = 0;
        if(i>li) li = i;
        if(j>lj) lj = j;

        dfs(grid, i-1, j, li, lj);
        dfs(grid, i+1, j, li, lj);
        dfs(grid, i, j-1, li, lj);
        dfs(grid, i, j+1, li, lj);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
       int row = land.size(), col = land[0].size();
       vector<vector<int>> ans;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(land[i][j] == 1){
                    int li = i, lj = j;
                    dfs(land, i, j, li,lj); // Marking vistied 1's as 0.
                    ans.push_back({i,j,li,lj});
                } 
            }
        }
        return ans; 
    }
};