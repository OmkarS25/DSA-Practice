class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size(), ans = 0, mod = 1e9+7;
        unordered_map<int,vector<int>> mp;

        for (int i=0; i<n; i++)
            mp[nums[i]].push_back(i);

        for (int i=0; i<n; i++) {
            int num = 2 * nums[i];
            if(mp.find(num) == mp.end()) continue;

            auto &v = mp[num];
            int size = v.size();
            if(size < 2) continue;

            int ind = lower_bound(v.begin(), v.end(), i) - v.begin();
            int a = ind, b = size-ind;

            if(ind<size && v[ind] == i) b--;
            if(a>0 && b>0) ans = (ans+1LL*a*b)%mod;
        }
        return ans;
    }
};