class Solution {
public:
    void permutations(vector<int> nums, int start, set<vector<int>>& res) { 
        if (start == nums.size()) { 
            res.insert(nums); 
            return; 
        } 
        for (int i = start; i < nums.size(); i++) { 
            swap(nums[start], nums[i]);
            permutations(nums, start+1, res); 
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int> > res;  
        permutations(nums, 0, res);
        return vector<vector<int>>(res.begin(), res.end());
    }
};