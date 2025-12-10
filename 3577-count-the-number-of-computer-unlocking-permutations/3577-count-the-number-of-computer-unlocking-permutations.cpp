class Solution {
public:
    int countPermutations(vector<int>& v) {
        int n = v.size(), ans = 0, mod = 1e9+7;
        sort(v.begin()+1, v.end());
        if(v[0] >= v[1]) return 0;
        ans++;
        for(int i=1; i<n; i++){
            ans = (1LL*ans*i)%mod;
        }
        return ans;
    }
};