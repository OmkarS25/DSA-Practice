class Solution {
public:
    void solve(vector<int> nums, int index, vector<int> temp, vector<vector<int>> &subsets){
        if(index >= nums.size()){
            subsets.push_back(temp);
            return;
        }
        solve(nums, index+1, temp, subsets);
        temp.push_back(nums[index]);
        solve(nums, index+1, temp, subsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, {}, ans);
        return ans;
    }
};