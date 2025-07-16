class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0, alt0 = 0, alt1 = 0;

        // Count evens and odds
        for (int num : nums) {
            if (num % 2 == 0) even++;
            else odd++;
        }

        // Try alternating starting with 0 and 1
        int c = 0;
        for (int num : nums) {
            if (num % 2 == c) {
                alt0++;
                c = !c;
            }
        }

        c = 1;
        for (int num : nums) {
            if (num % 2 == c) {
                alt1++;
                c = !c;
            }
        }

        return max({odd, even, alt0, alt1});
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();