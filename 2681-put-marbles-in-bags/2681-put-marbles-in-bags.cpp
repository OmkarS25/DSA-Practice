class Solution {
public:
    long long putMarbles(vector<int> &weights, int k){
        int n = weights.size();
        vector<int> boundaryWeights;
        for(int i=0; i<n-1; i++)
            boundaryWeights.push_back(weights[i] + weights[i+1]);
        sort(boundaryWeights.begin(), boundaryWeights.end());
        long long ans = 0;
        for(int i=0; i<k-1; i++)
            ans += 1LL * boundaryWeights[n-i-2] - boundaryWeights[i];
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();