class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), ans = 0;
        for (int i = 1; i < n; i++) {
            int maxi = 0; // largest value balloon in substring
            while (i < n and colors[i] == colors[i - 1]) {
                ans += neededTime[i - 1];
                maxi = max(maxi, neededTime[i - 1]);
                ++i;
            }
            ans += neededTime[i - 1];
            maxi = max(maxi, neededTime[i - 1]);
            if (maxi != 0) ans -= maxi;
        }
        return ans;
    }
};