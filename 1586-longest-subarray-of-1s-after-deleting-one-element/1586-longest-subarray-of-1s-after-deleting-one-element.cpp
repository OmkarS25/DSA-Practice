class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();
        int one = 0, zero = 0, res = 0;
        for(int i=0; i<n; i++){
            if(!nums[i]) zero++;
            while(zero>1){
                if(!nums[one]) zero--;
                one++;
            }
            res = max(res, i-one);
        }
        return res;
    }
};