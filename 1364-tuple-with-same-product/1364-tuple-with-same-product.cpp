class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productFreq;
        const int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productFreq[product]++;
            }
        }
        for (auto& [product, count] : productFreq) {
            if (count > 1) res += (count * (count - 1)) / 2;
        }
        return res * 8;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();