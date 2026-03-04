class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        const int n = mat.size(), m = mat[0].size();
        int cnt = 0;
        vector<int> row(n,0), col(m,0);
        // Store in which rows and cols have mutliple 1's.
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(1 == mat[i][j]){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        // Check if the 1 is in a special position or not.
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(1 == mat[i][j] && 1 == row[i] && 1 == col[j])
                    cnt++;
            }
        }
        return cnt;
    }
};