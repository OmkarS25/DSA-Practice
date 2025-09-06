class Solution {
    long getOperations(int n) {
        long res = 0;
        int ops = 0;
        for (int powerOfFour = 1; powerOfFour <= n; powerOfFour *= 4) {
            int left = powerOfFour;
            int right = min(n, powerOfFour * 4 - 1);
            res += static_cast<long>(right - left + 1) * ++ops;
        }
        return res;
    }

public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            long totalDivisions = getOperations(r) - getOperations(l - 1);
            ans += (totalDivisions + 1) / 2; // ceil division
        }
        return ans;
    }
};
