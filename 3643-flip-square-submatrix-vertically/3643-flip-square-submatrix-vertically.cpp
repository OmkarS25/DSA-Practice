class Solution {
public:
    static vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int startRow, int startCol, int size) {
        for(int top = startRow, bottom = startRow + size - 1; top < bottom; top++, bottom--) {
            for(int col = startCol; col < startCol + size; col++) {
                swap(grid[top][col], grid[bottom][col]);
            }
        }
        return grid;
    }
};
