static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n != original.size()) return {};
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int index = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++, index++){
                ans[i][j] = original[index];
            }
        }
        return ans;
    }
};