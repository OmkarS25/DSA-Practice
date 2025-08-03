class Solution {
public:
    int findRight(int distance, const vector<vector<int>> &fruits) {
        int output = 0, left = 0, right = fruits.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) >> 1);
            if (fruits[middle][0] <= distance) {
                output = middle;
                left = middle + 1;
            } else right = middle - 1;
        }
        return output;
    }
    int findLeft(int distance, const vector<vector<int>> &fruits) {
        int output = 0, left = 0, right = fruits.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) >> 1);
            if (fruits[middle][0] >= distance) {
                output = middle;
                right = middle - 1;
            } else left = middle + 1;
        }
        return output;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + fruits[i - 1][1]; 
        }
        long long output = 0;
        for (int left = 0; left < fruits.size(); ++left) {
            int needed = abs(fruits[left][0] - startPos);
            if (needed > k) continue;
            if (fruits[left][0] > startPos) {
                int right = findLeft(startPos - max(0, k - 2 * needed), fruits);
                output = max(output, prefix[left + 1] - prefix[right]);
            } else {
                int right = findRight(startPos + max(0, k - 2 * needed), fruits);
                output = max(output, prefix[right + 1] - prefix[left]);
            }
        }
        return static_cast<int>(output);
    }
};
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();