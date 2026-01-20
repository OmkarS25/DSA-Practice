class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int curr_ans = -1;
            for(int j=0; j<=nums[i]; j++){
                if((j|j+1) == nums[i]){
                    curr_ans = j;
                    break;
                }
            }
            ans.push_back(curr_ans);
        }
        return ans;
    }
};