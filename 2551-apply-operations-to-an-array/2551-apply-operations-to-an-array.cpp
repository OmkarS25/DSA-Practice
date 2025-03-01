class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int index = 0; // Pointer to track the position for non-zero elements

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && nums[i] == nums[i + 1]) {
                nums[i] *= 2; // Double the current element
                nums[i + 1] = 0; // Set the next element to 0
            }

            // Shift non-zero elements to the front
            if (nums[i] != 0) {
                nums[index] = nums[i]; // Place non-zero element at the current index
                if (index != i) {
                    nums[i] = 0; // Set the original position to 0 if it was moved
                }
                index++; // Move the index forward
            }
        }

        // Fill the remaining positions with zeros
        while (index < n) {
            nums[index++] = 0;
        }

        return nums;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();