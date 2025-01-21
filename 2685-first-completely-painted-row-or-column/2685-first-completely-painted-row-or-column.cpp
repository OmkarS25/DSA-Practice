class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        // Map to store the position of each element in mat
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }

        // Row and column counters
        vector<int> rowCounter(n, m), colCounter(m, n);

        // Process the sequence in arr
        for (int index = 0; index < arr.size(); index++) {
            int val = arr[index];
            auto [row, col] = pos[val];

            // Decrement the counters for the row and column
            rowCounter[row]--;
            colCounter[col]--;

            // Check if the row or column is complete
            if (rowCounter[row] == 0 || colCounter[col] == 0) {
                return index;
            }
        }

        return -1; 
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();