class Solution {
public:
    int countPermutations(vector<int>& v) {
        const int n = v.size(), mod = 1e9+7;
        long long ans = 1;
        for (int i=1; i<n; i++) {
            if (v[i] <= v[0]) return 0;
            ans = (ans*i)%mod;
        }
        return ans;
    }
};