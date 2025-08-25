class Solution {
    void diagonal(vector<vector<int>>& mat, vector<int>& res, int& i, int& j, bool& upside){
        const int n = mat.size(), m = mat[0].size();
        if (upside) {
            while (i>=0 && j<m) res.push_back(mat[i--][j++]);
            if (j>=m) i+=2, j=m-1; 
            else  i=0;
        } else {
            while (i<n && j>=0) res.push_back(mat[i++][j--]);
            if (i>=n) j+=2, i=n-1;
            else j=0;
        }
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int n = mat.size(), m = mat[0].size();
        vector<int> res;
        int i=0, j=0;
        bool upside = true;
        while (res.size() < n * m) {
            diagonal(mat, res, i, j, upside);
            upside = !upside;
        }
        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();