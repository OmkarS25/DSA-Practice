class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> storePairs;
        for (int i = 0; i < nums.size(); ++i) {
            int mappedValue = 0;
            int temp = nums[i];
            // Start making changes from the units place.
            int place = 1;
            // If the value initially is 0, return mapping[0] and index.
            if (temp == 0) {
                storePairs.push_back({mapping[0], i});
                continue;
            }
            // Repeat the process for units, tenths, hundredths.. places.
            while (temp != 0) {
                mappedValue = place * mapping[temp % 10] + mappedValue;
                place *= 10;
                temp /= 10;
            }
            storePairs.push_back({mappedValue, i});
        }
        // Sort the array in non-decreasing order by the first value (default).
        sort(storePairs.begin(), storePairs.end());
        vector<int> answer;
        for (auto pair : storePairs) {
            answer.push_back(nums[pair.second]);
        }
        return answer;
    }
};

// My code which is not working
// class Solution {
// public:
//     vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
//         sort(nums.begin(), nums.end(), [&mapping](int a, int b){
//             int a_val = 0, b_val = 0;
//             while(a){
//                 a_val *= 10;
//                 a_val += a%10;
//                 a /= 10;
//             }
//             while(a_val){
//                 a *= 10;
//                 a += mapping[a_val%10];
//                 a_val /= 10;
//             }
//             while(b){
//                 b_val *= 10;
//                 b_val += b%10;
//                 b /= 10;
//             }
//             while(b_val){
//                 b *= 10;
//                 b += mapping[b_val%10];
//                 b_val /= 10;
//             }
//             return a < b;
//         });
//         return nums;
//     }
// };

// ChatGPT code
// class Solution {
// public:
//     vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
//         auto transform = [&mapping](int num) -> int {
//             string mappedValue;
//             if (num == 0) {
//                 mappedValue += mapping[0] + '0';
//             } else {
//                 while (num > 0) {
//                     mappedValue += mapping[num % 10] + '0';
//                     num /= 10;
//                 }
//                 reverse(mappedValue.begin(), mappedValue.end());
//             }
//             return stoi(mappedValue);
//         };
//         sort(nums.begin(), nums.end(), [&mapping, &transform](int a, int b) {
//             return transform(a) < transform(b);
//         });
        
//         return nums;
//     }
// };
