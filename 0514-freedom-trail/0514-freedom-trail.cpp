class Solution {
public:
    int solve(string ring, string key, int ptr1, int ptr2, vector<vector<int>>& dp){
        int n = ring.size();
        int m = key.size();
        if(ptr2>=m) return 0;
        if(dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];
        int steps = INT_MAX;
        for(int i=0; i<n; i++){
            if(ring[i] == key[ptr2]){
                steps = min(steps, min(abs(i-ptr1), n-abs(i-ptr1))+1+solve(ring,key,i,ptr2+1,dp));
            }
        }
        return dp[ptr1][ptr2] = steps;
    }
    int findRotateSteps(string ring, string key){
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(ring, key, 0, 0, dp);
    }
};