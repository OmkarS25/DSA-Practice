class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int num = nums[0], count = 0, numCount = 0, n = nums.size();
        for (int x : nums) {
            if (num == x) count++;
            else count--;
            if (count == 0) {
                num = x;
                count = 1;
            }
        }
        for (int x : nums) {
            if (num == x) numCount++;
        }

        count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == num) count++;
            int remaining = numCount - count;
            bool left = count * 2 > (i + 1);
            bool right = remaining * 2 > (n - i - 1);
            if (left && right) return i;
        }
        return -1;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();