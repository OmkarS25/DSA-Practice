class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0, res = 0;

        for(int i : nums) total += i;
        
        int left = 0, right = total;
        
        for(int i=0; i<nums.size()-1; i++){
            left += nums[i];
            right -= nums[i];
            if(abs(left - right)%2 == 0) res++;
        }

        return res;
    }
};