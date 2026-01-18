class Solution {
    bool isMagicSquare(vector<vector<int>>& grid, int x0, int y0, int k){
        long long final_sum = -1;

        // Check rows
        for(int i = x0; i < x0 + k; i++){
            long long sum = 0;
            for(int j = y0; j < y0 + k; j++){
                sum += grid[i][j];
            }
            if(final_sum == -1) final_sum = sum;
            else if(final_sum != sum) return false;
        }

        // Check columns
        for(int j = y0; j < y0 + k; j++){
            long long sum = 0;
            for(int i = x0; i < x0 + k; i++){
                sum += grid[i][j];
            }
            if(final_sum != sum) return false;
        }

        // Check main diagonal (top-left to bottom-right)
        long long diag1 = 0;
        for(int i = 0; i < k; i++){
            diag1 += grid[x0 + i][y0 + i];
        }
        if(final_sum != diag1) return false;

        // Check anti-diagonal (top-right to bottom-left)
        long long diag2 = 0;
        for(int i = 0; i < k; i++){
            diag2 += grid[x0 + i][y0 + k - 1 - i];
        }
        if(final_sum != diag2) return false;

        return true;
    }

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        int maxAns = 1;

        // Try all possible square sizes
        for(int k = min(n, m); k >= 2; k--){ // largest to smallest
            for(int i = 0; i + k <= n; i++){
                for(int j = 0; j + k <= m; j++){
                    if(isMagicSquare(grid, i, j, k)){
                        return k; // largest found
                    }
                }
            }
        }
        return maxAns; 
    }
};
