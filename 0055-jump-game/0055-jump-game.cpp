class Solution {
public:
    bool solve(vector<int>& nums, int index, vector<int>& memo){
        if(index >= nums.size()-1) return true;
        if(nums[index] == 0) return false;
        if(memo[index] != -1) return memo[index];

        for(int i=1; i<=nums[index]; i++){
            if(solve(nums, index+i, memo)){
                memo[index] = 1;
                return true;
            }
        }
        memo[index] = 0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, 0, memo);
    }
};