class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int ans = 0;
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i] == nums[i+1])
        //         return nums[i];
        // }
        // return -1;
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[0] == nums[nums[0]]){
                ans = nums[0];
                break;
            }
            swap(nums[0], nums[nums[0]]);
        }
        return ans;
    }
};