class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 1 || k == 0) return false;
        unordered_map<int, int> list;
        // Intial counting
        for(int i=0; i<=k && i<nums.size(); i++){
            if(list[nums[i]]) return true;
            list[nums[i]]++;
        }
        // Slinding Window
        for(int i=k+1; i<nums.size(); i++){
            list[nums[i-k-1]]--;
            if(list[nums[i]]) return true;
            list[nums[i]]++;
        }
        return false;
    }
};