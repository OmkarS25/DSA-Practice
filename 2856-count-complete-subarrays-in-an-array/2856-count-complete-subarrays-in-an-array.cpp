class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> distinctSet(nums.begin(), nums.end());
        const int distinctCount = distinctSet.size(), len = nums.size();
        int count = 0;
        for (int i = 0; i < len; i++) {
            unordered_set<int> tempSet;
            for (int j = i; j < len; j++) {
                tempSet.insert(nums[j]);
                if (tempSet.size() == distinctCount) {
                    count += len - j;
                    break;
                }
            }
        }
        return count;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();

// 1480 ms submit time
// class Solution {
// public:
//     int countCompleteSubarrays(vector<int>& nums) {
//         unordered_set<int> *distinctSet = new unordered_set<int>(nums.begin(), nums.end());
//         const int distinctCount = distinctSet->size(), len = nums.size();
//         delete distinctSet;
//         int count = 0;
//         for (int i = 0; i < len; i++) {
//             unordered_set<int> tempSet;
//             for (int j = i; j < len; j++) {
//                 tempSet.insert(nums[j]);
//                 if (tempSet.size() == distinctCount) {
//                     count += len - j;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };