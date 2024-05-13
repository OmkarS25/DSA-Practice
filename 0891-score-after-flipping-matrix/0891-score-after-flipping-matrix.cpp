class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        // Making max rows
        for(int i=0; i<rows; i++){
            if(0 == grid[i][0]){
                for(int j=0; j<grid[0].size(); j++){
                    grid[i][j] = grid[i][j]^1;
                }
            } 

        }
        // Making max cols
        for(int j=0; j<cols; j++){
            int count0=0, count1=0;
            for(int i=0; i<rows; i++){
                if(grid[i][j] == 0) count0++;
                else count1++;
            }
            if(count0>count1){
                for(int i=0; i<rows; i++){
                    grid[i][j] = grid[i][j]^1;
                }
            }
        }
        // Counting the numbers
        int score = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]) score =  score + pow(2, cols-1-j);
            }
        }
        return score;
    }
};