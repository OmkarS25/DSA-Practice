class Solution {
public:
    string maxSumOfSquares(size_t num, size_t sum) const noexcept {
        if (num * 9 < sum) return {};
        size_t quotient = sum / 9, rem = sum % 9;
        string ans(num, '0');
        fill(ans.begin(), ans.begin() + quotient, '9');
        if (rem) ans[quotient] = '0' + rem;
        return ans;
    }
};