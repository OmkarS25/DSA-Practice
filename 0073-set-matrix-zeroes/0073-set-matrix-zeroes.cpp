class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        set<int> rows, cols; // These rows and cols needs to be zeroed.
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        // Zeroing the rows
        for (const auto& num : rows){
            for(int i=0; i<m; i++){
                matrix[num][i] = 0;
            }
        }
        // Zeroing the cols
        for (const auto& num : cols){
            for(int i=0; i<n; i++){
                matrix[i][num] = 0;
            }
        }
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();