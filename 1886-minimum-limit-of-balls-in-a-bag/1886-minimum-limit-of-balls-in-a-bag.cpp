class Solution {
public:
    bool possible_ans(vector<int>& nums,int maxOperations,int mid){
        int currentOperations = 0;
        for(auto &it : nums){
            if( it % mid==0){
                currentOperations += it/mid;
                currentOperations--;
            }
            else{
                currentOperations += ( it + mid -1)/mid;
                currentOperations--;
            }
            if(currentOperations > maxOperations) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start=1, result=0, end=*max_element(nums.begin(),nums.end());
        while(start <=end){
            int mid = start+(end-start)/2;
            if(possible_ans(nums,maxOperations,mid)){
                result = mid;
                end = mid-1;
            }
            else start=mid+1;
        }
        return result;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();