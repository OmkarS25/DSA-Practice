class Solution {
public:
    int maxLength(vector<int>& nums) {
        vector bitMask = {0, 1, 2, 1, 4, 3, 8, 1, 2, 5};
        int ans = 2, Mask = 0;
        int i = 0, j = 0, n = nums.size();
        while (i < n && j < n) {
            while ((Mask & bitMask[nums[i] - 1]) && j < n) {
                Mask = Mask ^ bitMask[nums[j] - 1];
                j++;
            }
            Mask = Mask ^ bitMask[nums[i] - 1];
            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};