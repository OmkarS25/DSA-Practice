class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = 0;
        bool start = false;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                if(start){
                    if(n < k) return false;
                    else n=0;
                } else start = true;
            }
            else if (start) n++;
        }
        return true;
    }
};