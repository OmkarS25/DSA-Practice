class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.back() - nums.front();
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (canFormPairs(nums, p, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }

private:
    bool canFormPairs(const vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                ++count;
                ++i; // Skip the next element to form a pair
            }
        }
        return count >= p;
    }
};


// class Solution {
// public:
//     int minimizeMax(vector<int>& nums, int p) {
//         if(p == 0) return 0;
//         sort(nums.begin(), nums.end());
//         vector<int> diffList;
//         for(int i=0; i<nums.size()-1; i++){
//             diffList.push_back(nums[i+1] - nums[i]);
//         }
//         sort(diffList.begin(), diffList.end());
//         return diffList[p-1];
//     }
// };