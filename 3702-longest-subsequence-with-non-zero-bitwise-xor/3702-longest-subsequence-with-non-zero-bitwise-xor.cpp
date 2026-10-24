class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // if arrray is full of zeros return 0
        // if entire array is not full of zeros and we still get zero, we can
        // remove any one leading the answer to be one less than size else we
        // can simply return size of array in case the xor is positive
        int total_xor = 0;
        bool all_zeros = true;

        for (int num : nums) {
            if (num != 0) all_zeros = false;
            total_xor ^= num; 
        }

        if (all_zeros) return 0;
        if (total_xor > 0) return nums.size();
        
        return nums.size() - 1;
    }
};