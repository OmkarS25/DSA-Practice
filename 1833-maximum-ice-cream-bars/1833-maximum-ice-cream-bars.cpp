class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int answer = 0;
        for(int element : costs) {
            if(element > coins)  break;
            coins -= element;
            answer++;
        }
       return answer;
    }
};


// MLE
// class Solution {
// public:
//     int solve(vector<int>&costs, int coins, int i, vector<vector<int>>& dp){
//         if(i >= costs.size() || coins <= 0) return 0;
//         if(dp[coins][i] != -1) return dp[coins][i];

//         int include = 0, exclude = 0;
//         if(costs[i] <= coins)
//             include = 1 + solve(costs, coins-costs[i], i+1, dp);
//         exclude = 0 + solve(costs, coins, i+1, dp);
//         dp[coins][i] = max(include, exclude);
//         return dp[coins][i];
//     }
//     int maxIceCream(vector<int>& costs, int coins) {
//         vector<vector<int>> dp(coins+1, vector<int>(costs.size(), -1));
//         return solve(costs, coins, 0, dp);
//     }
// };