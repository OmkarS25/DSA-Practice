class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }
        if(i<2 || i==n) return false;
        while(i<n && nums[i]<nums[i-1]){
            i++;
        }
        if(i<3 || i==n) return false;
        while(i<n && nums[i]>nums[i-1]){
            i++;
        }
        return i==n;
    }
};