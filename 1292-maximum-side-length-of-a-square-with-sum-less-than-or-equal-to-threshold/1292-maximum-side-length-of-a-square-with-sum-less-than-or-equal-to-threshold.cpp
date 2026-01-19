class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        const int m = mat.size(), n = mat[0].size();
        
        // Build prefix sum matrix
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
        
        int maxEdge = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Binary search for largest square starting at (i,j)
                int low = maxEdge + 1, high = min(m - i, n - j);
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    int sum = getSquareSum(i, j, i + mid - 1, j + mid - 1, prefix);
                    if (sum <= threshold) {
                        maxEdge = mid;
                        low = mid + 1;
                    } else high = mid - 1;
                }
            }
        }
        return maxEdge;
    }

private:
    int getSquareSum(int x1, int y1, int x2, int y2, vector<vector<int>>& prefix) {
        // Convert to 1-based indexing for prefix
        x1++; y1++; x2++; y2++;
        return prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
    }
};
