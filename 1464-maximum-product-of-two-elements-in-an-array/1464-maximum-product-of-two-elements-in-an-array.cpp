class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i=nums.size()-1;
        int j=i-1;
        sort(nums.begin(),nums.end());
        return (nums[i]-1)*(nums[j]-1);
    }
};