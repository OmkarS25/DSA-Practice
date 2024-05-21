class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0=0,n1=0,n2=0;
        int size=nums.size();
        for(int i=0; i<size; i++){
            if(nums[i]==0){
                n0++;
            }
            else if (nums[i]==1){
                n1++;
            }
            else if (nums[i]==2){
                n2++;
            }
        }
        int index=0;
        while(n0--){
            nums[index]=0;
            index++;
        }
        while(n1--){
            nums[index]=1;
            index++;
        }
        while(n2--){
            nums[index]=2;
            index++;
        }
    }
};