class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patches = 0;
        long long miss = 1;
        size_t i = 0;
        while(miss <= n){
            if(i<nums.size() && nums[i] <= miss) 
                miss += nums[i++];
            else{
                miss += miss;
                patches++;
            }
        }
        return patches;
    }
};