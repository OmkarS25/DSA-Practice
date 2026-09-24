class Solution {
    int digit_total(int n){
        int ans = 0;
        while(n){
            int rem = n % 10;
            ans += rem;
            n /= 10;
        }
        return ans;
    }
public:
    int smallestIndex(vector<int>& nums) {
        const int n = nums.size();
        for(int i=0; i<n; i++){
            if(digit_total(nums[i]) == i) return i;
        }
        return -1;
    }
};