class Solution {
public:

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) return true;
        if(n < 2*k) return false;
        vector<int> len(n, 1);
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]) len[i] = len[i-1] + 1;
        }
        for(int i=k-1; i+k<n; i++){
            if(len[i]>=k && len[i+k]>=k) return true;
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n;
        int ans = 1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(hasIncreasingSubarrays(nums, mid)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};