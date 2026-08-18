// Solution - 2
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        const int n = nums.size();
        if(n == 1) return nums[0];
        if(k == n) return *max_element(nums.begin(), nums.end());

        unordered_map<int,int> freq;
        int ans = -1;

        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        if(k == 1){
            for (const auto &pair : freq) {
                if(pair.second == 1) ans = max(ans, pair.first);
            }
        }
        if(freq[nums[0]] == 1) ans = max(ans, nums[0]);
        if(freq[nums[n-1]] == 1) ans = max(ans, nums[n-1]);

        return ans;
    }
};



// // Solution - 1
// class Solution {
// public:
//     int largestInteger(vector<int>& nums, int k) {
//         const int n = nums.size();
//         if(n == 1) return nums[0];

//         unordered_map<int,int> freq;
//         int ans = -1;

//         for(int i=0; i<n; i++){
//             freq[nums[i]]++;
//         }

//         if(k == 1 || k == n){
//             for (const auto &pair : freq) {
//                 if(pair.second == 1 || k == n) ans = max(ans, pair.first);
//             }
//         }
//         else{
//             if(freq[nums[0]] == 1) ans = max(ans, nums[0]);
//             if(freq[nums[n-1]] == 1) ans = max(ans, nums[n-1]);
//         }

//         return ans;
//     }
// };



// Testcases

// [30,33,31,27,47,21,25,8,7,29,35,10,12,19,11,39,1,0,1,6,6,9,22,42,21,36,10,5,4]
// 1
// [43,16,6,11,9,10,0,45,26,3,18,5,5,20,14,35,48,42,50,46,30,8,38,21,47,25,2,26,37,31]
// 30
// [15,15,16,39,7,37,44,28,4,26,31,37,16,36,30,39,23,26,21,1,18,24,33,39]
// 24
// [44,40,26,5,29,46,12,10,12,14,48,3,21,2,41,10,18,14,33]
// 1
// [30,31,30,21,31,17,45,38,7,3,39,42,19,49,19,20]
// 10
// [48,47,48,16,2,11,27,4,48,0,5,9]
// 3
// [22,16,21,17,19,15,21,40,30,1,18]
// 1
// [12,37,16,19,30,46,5,39,3,27,41,8,22,1,31,25,25,13,5,28,50,2,42,0,49,37,46,44,29,21]
// 20
// [0,3,1]
// 1
// [3,0,12,7,1,11]
// 6
// [0,0]
// 2
// [10,12,9,7,10]
// 3