class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int len = nums.size();
        sort(nums.begin(), nums.end()); // Sort the input array first

        for(int i = 0; i < len - 2; ++i) {
            // Avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i]; // Find two numbers that sum up to -nums[i]
            int left = i + 1;
            int right = len - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) ++left;
                else if (sum > target) --right; 
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // Avoid duplicates
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                }
            }
        }
        return ans;
    }
};
