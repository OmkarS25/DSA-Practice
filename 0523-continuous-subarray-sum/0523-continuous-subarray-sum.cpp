class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1; // For cases where subarray starts at 0.
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum = (sum + nums[i]) % k;
            if (prefix_map.find(sum) != prefix_map.end()) {
                if (i - prefix_map[sum] > 1)  return true;
            } 
            else prefix_map[sum] = i;
        }
        return false;
    }
};

// Testcases:
// 1. [23,2,4,6,6] - 7
// 2. [1,0] - 2
// 3. [0] - 1
// 4. [0,1,0,3,0,4,0,4,0] - 5 
// 5. [0,0] - 1

// My solution but was not able to solve all testcases.
// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         if(nums.size() == 1) return false;
//         vector<int> prefix;
//         int sum = 0;
//         for(int a: nums){
//             sum = (sum+a)%k;
//             prefix.push_back(sum);
//             if(sum == 0 && a != 0) return true;
//         }
//         for(int i=0; i<prefix.size(); i++){
//             for(int j=i+1; j<prefix.size(); j++){
//                 if(prefix[i] == prefix[j]) 
//                     return true;
//             }
//         }
//         return false;
//     }
// };