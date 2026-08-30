class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        const int n = nums.size();
        int minIndex = 0, maxIndex = 0;

        // Find both the indexes to remove
        for(int i=1; i<n; i++){
            if(nums[minIndex] > nums[i]) minIndex = i;
            if(nums[maxIndex] < nums[i]) maxIndex = i;
        }

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // Remove both from the front
        int front = right + 1;

        // Remove both from the back
        int back = n - left;

        // Remove one from each side
        int frontBack = (left + 1) + (n - right);

        return min({front, back, frontBack});
    }
};