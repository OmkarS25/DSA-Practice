class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = 0, left_sum = 0;
        for (int num : nums) total_sum += num;
        for (int i = 0; i < nums.size(); ++i) {
            if (left_sum == total_sum - left_sum - nums[i]) return i;
            left_sum += nums[i];
        }
        return -1;
    }

    // MY solution
    // int pivotIndex(vector<int>& nums){
    // int index = -1, n = nums.size();
    // for(int i=0; i<n; i++){
    //     int left=0, right=0;
    //     for(int j=0; j<n; j++){
    //         if(j<i) left += nums[j];
    //         else if(j>i) right += nums[j]; 
    //     }
    //     if(left == right){
    //         index = i;
    //         break;
    //     }
    // }
    // return index;
    // }

    // accumulate example
    // int pivotIndex(vector<int>& nums) {
    //    for(int i=0;i<nums.size();i++){
    //     int a=accumulate(nums.begin(),nums.begin()+i,0);
    //     int b=accumulate(nums.begin()+i+1,nums.end(),0);
    //     if(a==b){
    //         return i;
    //     }
    //    }
    // return -1;
    // }
};