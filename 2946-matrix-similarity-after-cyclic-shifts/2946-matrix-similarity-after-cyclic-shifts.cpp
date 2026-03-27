class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        const int n = mat.size(), m = mat[0].size();
        k = k % m;  // Reduce redundant full cycles

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int originalIndex;
                if(i % 2 == 0) originalIndex = (j + k) % m; // Even row → left shift
                else originalIndex = (j - k + m) % m;  // Odd row → right shift

                // Check if value matches expected position
                if(mat[i][j] != mat[i][originalIndex])  return false;
            }
        }
        return true;
    }
};