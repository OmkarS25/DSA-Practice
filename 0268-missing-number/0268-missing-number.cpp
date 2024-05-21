class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size(), missingno = 0;
        // sort(nums.begin(), nums.end());
        for(int i=0; i<len; i++){
            missingno = missingno ^ nums[i] ^ (i+1);
        }
        return missingno;
    }
};