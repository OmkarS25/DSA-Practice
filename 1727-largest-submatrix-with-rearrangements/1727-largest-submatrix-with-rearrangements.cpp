class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        const int n=mat.size(),m=mat[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]!=0) mat[i][j]+=mat[i-1][j];
            }
        }
        int maxq=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int>vec=mat[i];
            sort(vec.begin(),vec.end(),greater<int>());
            for(int j=0;j<m;j++) maxq=max(maxq,(j+1)*vec[j]);
        }
        return maxq;
    }
};