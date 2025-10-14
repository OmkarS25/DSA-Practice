// slightly modified
class Solution {
public:
    static bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        const int n=nums.size();
        int curr=1, prev=0;
        for (int i=1; i<n && max(curr/2, min(curr, prev))<k; i++){
            if (nums[i]>nums[i-1]) curr++; 
            else prev=curr, curr=1;
        }
        return max(curr/2, min(curr, prev))>=k;
    }
};