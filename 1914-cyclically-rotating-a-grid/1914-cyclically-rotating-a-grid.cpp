class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        int layers = 0;
        int start1 = 0, end1 = m - 1, start2 = 0, end2 = n - 1;
        while(layers < min(n,m)/2)
        {
            //convert one layer into a 1d array
            vector<int> layer;
            for(int i = start2; i <= end2; i++) layer.push_back(grid[start1][i]);
            for(int i = start1 + 1; i <= end1; i++) layer.push_back(grid[i][end2]);
            for(int i = end2 - 1; i >= start2; i--) layer.push_back(grid[end1][i]);
            for(int i = end1 - 1; i > start1; i--) layer.push_back(grid[i][start2]);

            //rotate k times
            int newk = k % layer.size();
            for(int i = 0; i < newk; i++)
            {
                layer.push_back(layer[i]);
            }

            //replace the values of grid with the rotated values of 1d array
            int idx = newk;
            for(int i = start2; i <= end2; i++) grid[start1][i] = layer[idx++];
            for(int i = start1 + 1; i <= end1; i++) grid[i][end2] = layer[idx++];
            for(int i = end2 - 1; i >= start2; i--) grid[end1][i] = layer[idx++];
            for(int i = end1 - 1; i > start1; i--) grid[i][start2] = layer[idx++];

            //next layer
            layers++, start1++, start2++, end1--, end2--;
        }

        return grid;
    }
};