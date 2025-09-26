class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = nums[i] + nums[j];
                int index = lower_bound(nums.begin()+j+1, nums.end(), sum) - nums.begin();
                count += (index - j-1);
            }
        }
        return count;
    }
};