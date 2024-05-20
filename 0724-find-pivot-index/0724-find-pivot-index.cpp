class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int index = -1, n = nums.size();
        for(int i=0; i<n; i++){
            int left=0, right=0;
            for(int j=0; j<n; j++){
                if(j<i) left += nums[j];
                else if(j>i) right += nums[j]; 
            }
            if(left == right){
                index = i;
                break;
            }
        }
        return index;
    }
};