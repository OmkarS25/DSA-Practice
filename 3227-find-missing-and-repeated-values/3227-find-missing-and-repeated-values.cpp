class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int repeated, n = grid.size();
        vector<int> freq(n*n + 1, 0);

        for(auto row : grid) {
            for(int num : row) {
                if(freq[num] == 1) repeated = num;
                freq[num]++;
            }
        }

        for(int i = 1; i <= n * n; i++){
            if(freq[i] == 0) return {repeated, i};
        }
        return {-1, -1};
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();