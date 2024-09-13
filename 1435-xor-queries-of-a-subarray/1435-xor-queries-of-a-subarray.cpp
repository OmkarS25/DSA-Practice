#pragma GCC optimize("O3", "unroll-loops") 
static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), m = queries.size();
        vector<int> prefix(n), res(m);
        prefix[0] = arr[0];
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] ^ arr[i];
        for(int k=0; k<m; k++){
            int i=queries[k][0], j=queries[k][1];
            if(i==0) res[k] = prefix[j];
            else res[k] = prefix[j] ^ prefix[i-1];
        }
        return res;
    }
};