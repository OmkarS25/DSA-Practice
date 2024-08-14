class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minDistance = 0, maxDistance = nums.back() - nums.front();
        while(minDistance < maxDistance){
            int midDistance = minDistance + (maxDistance - minDistance)/2;
            if(countPairsWithinDistance(nums, midDistance) < k){
                minDistance = midDistance + 1;
            } else{
                maxDistance = midDistance;
            }
        }
        return minDistance;
    }
    int countPairsWithinDistance(const vector<int>& nums, int targetDistance) {
        int count = 0, left = 0;
        for (int right = 1; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > targetDistance) {
                ++left;
            }
            count += right - left;
        }
        return count;
    }
};