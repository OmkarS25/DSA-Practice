class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0, prev = INT_MIN, curr;
        for (int i=0; i<n; i++) {
            curr = min(max(nums[i] - k, prev + 1), nums[i] + k);
            if (curr > prev) {
                cnt++;
                prev = curr;
            }
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int maxDistinctElements(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         set<int> unique;
//         int lastUsed = INT_MIN;
//         for(int i=0; i<nums.size(); i++){
//             int rangeStart = max(lastUsed+1, nums[i]-k);
//             int rangeEnd = nums[i]+k;
//             if(rangeStart <= rangeEnd){
//                 unique.insert(rangeStart);
//                 lastUsed = rangeStart;
//             }
//         }
//         return unique.size();
//     }
// };