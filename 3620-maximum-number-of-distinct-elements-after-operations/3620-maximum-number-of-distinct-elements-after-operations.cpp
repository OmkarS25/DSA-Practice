class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<int> unique;
        int lastUsed = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int rangeStart = max(lastUsed+1, nums[i]-k);
            int rangeEnd = nums[i]+k;
            if(rangeStart <= rangeEnd){
                unique.insert(rangeStart);
                lastUsed = rangeStart;
            }
        }
        return unique.size();
    }
};