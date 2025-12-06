class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size(), mod = 1e9+7;
        vector<int> dp(n), preSum(n+2,0);
        queue<int> q;
        multiset<int> st;
        q.push(0); // Stores the index
        dp[0] = 1; preSum[2] = 2; preSum[1] = 1;
        st.insert(nums[0]);
        for(int i=1;i<n;i++){
            // Find the left bound
            while(!q.empty() && (abs(nums[i] - *st.begin()) > k || (abs(nums[i] - *st.rbegin()) > k))){
                st.erase(st.find(nums[q.front()]));
                q.pop();
            }
            st.insert(nums[i]);
            q.push(i);
            int ind = q.front();
            dp[i] = (preSum[i+1] - preSum[ind] + mod)%mod;
            preSum[i+2] = (preSum[i+1] + dp[i])%mod;
        }
        return dp[n-1];
    }
};