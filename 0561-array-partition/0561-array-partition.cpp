class Solution {
public:
    int arrayPairSum(vector<int> nums) {
        sort(nums.begin(), nums.end());
        // len = nums.size()/2;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(!(i&1)){
                sum += nums[i];
            }
        }
        return sum;
    }
};