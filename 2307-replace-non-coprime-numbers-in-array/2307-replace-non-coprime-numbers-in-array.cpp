class Solution {
public:
    [[nodiscard]] constexpr std::vector<int> replaceNonCoprimes(std::vector<int>& nums) noexcept {
        uint32_t n = 0;
        for (int b : nums) {
            while (n) {
                int& a = nums[n - 1];
                int gcd = std::gcd(a, b);
                if (gcd == 1) break;
                b *= a / gcd;
                --n;
            }
            nums[n++] = b;
        }

        nums.resize(n);
        return std::move(nums);
    }
};