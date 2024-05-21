class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0 ,end = nums.size()-1;
        int mid = (start+end)/2;
        int ans = nums.size();
        while(start <= end) {
            if(nums[mid] == mid) {
                start = mid + 1;
            }
            else if(nums[mid] != mid) {
                ans = mid;
                end = mid - 1;
            }
            mid = (start + end)/2;
        }
        return ans;
    }
};