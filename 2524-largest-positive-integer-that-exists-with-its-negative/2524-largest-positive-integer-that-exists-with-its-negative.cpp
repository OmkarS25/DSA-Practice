class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = -1, i = 0, j = nums.size()-1;
        sort(nums.begin(),nums.end());
        while(i<j){
            if(nums[i]>0) return maxi;
            if(nums[j]<0) return maxi;
            if(abs(nums[i]) == nums[j]){
                maxi = max(maxi,nums[j]);
                i++;
                j--;
            } 
            else if (abs(nums[i]) > nums[j]) i++;
            else if (abs(nums[i]) < nums[j]) j--;
        }
        return maxi;
    }
};